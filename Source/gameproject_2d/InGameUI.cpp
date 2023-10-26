// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameUI.h"
#include "Components/TextBlock.h"

void UInGameUI::SetMessage(const FString& Text)
{
	if (PlayerDialogTextBlock == nullptr) return;

	PlayerDialogTextBlock->SetText(FText::FromString(Text));
}


void UInGameUI::SetCharacterName(const FString& Text)
{
	if (CharacterNameText == nullptr) return;

	CharacterNameText->SetText(FText::FromString(Text));
}

void UInGameUI::AnimateMessage(const FString& Text)
{
	CurrentState = 1;

	InitialMessage = Text;

	OutputMessage = "";

	iLetter = 0;

	PlayerDialogTextBlock->SetText(FText::FromString(""));

	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this,
		&UInGameUI::OnAnimationTimerCompleted, DelayBetweenLetters, false);
}

void UInGameUI::OnAnimationTimerCompleted()
{
	GetWorld()->GetTimerManager().ClearTimer(TimerHandle);

	OutputMessage.AppendChar(InitialMessage[iLetter]);

	PlayerDialogTextBlock->SetText(FText::FromString(OutputMessage));

	if ((iLetter + 1) < InitialMessage.Len())
	{
		iLetter = iLetter + 1;
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this,
			&UInGameUI::OnAnimationTimerCompleted, DelayBetweenLetters, false);
	}
	else // Last letter, animation completed
	{
		CurrentState = 2;
	}
}

void UInGameUI::OnTimerCompleted()
{
	GetWorld()->GetTimerManager().ClearTimer(TimerHandle);

	// Start animating letter by letter
	AnimateMessage(Dialogue[RowIndex]->Messages[MessageIndex].ToString());
}

void UInGameUI::Interact()
{
	if (CurrentState == 1) // The text is being animated, skip
	{
		GetWorld()->GetTimerManager().ClearTimer(TimerHandle);

		PlayerDialogTextBlock->SetText(FText::FromString(InitialMessage));

		CurrentState = 2; // Text completed

	}
	else if (CurrentState == 2) // Text completed
	{
		// Get next message
		if ((MessageIndex + 1) < Dialogue[RowIndex]->Messages.Num())
		{
			MessageIndex += 1; // Start animating the next line

			AnimateMessage(Dialogue[RowIndex]->Messages[MessageIndex].ToString());
		}
		else // Last message of this row
		{
			PlayerDialogTextBlock->SetText(FText::FromString(""));
			CharacterNameText->SetText(FText::FromString("Blue Robot"));

			// Check if there is any answers
			if (Dialogue[RowIndex]->MessageOptions.Num() > 0)
			{
				OnResetOptions();

				for (int i = 0; i < Dialogue[RowIndex]->MessageOptions.Num(); i++)
				{
					OnSetOption(i, Dialogue[RowIndex]->MessageOptions[i].OptionText);
				}

				SelectectedOption = 0;

				OnHighLightOption(SelectectedOption);

				CurrentState = 3; // Wait to select answer

			}
			else
			{
				CurrentState = 0; // Complete the dialogue
				OnAnimationHideMessageUI();

			}
		}
	}

	else if (CurrentState == 3) // Wait to select answer
	{
		// Select current option and check if there is an answer for this one
		// Get the new row
		RowIndex = Dialogue[RowIndex]->MessageOptions[SelectectedOption].AnswerIndex;
		OnResetOptions();

		if ((RowIndex >= 0) && (RowIndex < Dialogue.Num()))
		{
			PlayerDialogTextBlock->SetText(FText::FromString(""));

			MessageIndex = 0;
			AnimateMessage(Dialogue[RowIndex]->Messages[MessageIndex].ToString());
		}
		else
		{
			CurrentState = 0; // Complete the dialogue
			OnAnimationHideMessageUI();

		}
	}
}

void UInGameUI::InitializeDialogue(class UDataTable* DialogueTable)
{
	CurrentState = 0;

	CharacterNameText->SetText(FText::FromString(""));
	PlayerDialogTextBlock->SetText(FText::FromString(""));

	OnResetOptions();

	Dialogue.Empty();

	// Initialize dialogue
	for (auto it : DialogueTable->GetRowMap())
	{
		FDialogNPC* Row = (FDialogNPC*)it.Value;

		Dialogue.Add(Row);
	}

	RowIndex = 0;

	if (Dialogue.Num() > 0)
	{
		CurrentState = 0;

		RowIndex = 0;

		CharacterNameText->SetText(FText::FromString(Dialogue[RowIndex]->CharacterName.ToString()));

		if (Dialogue[RowIndex]->Messages.Num() > 0)
		{
			MessageIndex = 0;

			OnAnimationShowMessageUI();

			GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &UInGameUI::OnTimerCompleted, 0.5f, false);

		}
	}

}

void UInGameUI::OnSelectUpOption()
{
	if (CurrentState != 3) return;

	if ((SelectectedOption - 1) >= 0)
	{
		SelectectedOption -= 1;
		OnHighLightOption(SelectectedOption);
	}
}

void UInGameUI::OnSelectDownOption()
{
	if (CurrentState != 3) return;

	if ((SelectectedOption + 1) < Dialogue[RowIndex]->MessageOptions.Num())
	{
		SelectectedOption += 1;
		OnHighLightOption(SelectectedOption);
	}
}