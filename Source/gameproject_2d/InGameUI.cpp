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

void UInGameUI::AnimateMessage(const FString& Name, const FString& Text)
{
	bTextCompleted = false;

	bAnimating = false;

	CharacterNameText->SetText(FText::FromString(Name));

	if (Text.Len() == 0) return;

	InitialMessage = Text;

	OutputMessage = "";

	iLetter = 0;

	OnAnimationShowMessageUI();

	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &UInGameUI::OnTimerCompleted, 0.5f, false);
}

void UInGameUI::OnTimerCompleted()
{
	if (!bAnimating) {
		bAnimating = true;
	}

	OutputMessage.AppendChar(InitialMessage[iLetter]);
	PlayerDialogTextBlock->SetText(FText::FromString(OutputMessage));

	if ((iLetter + 1) < InitialMessage.Len())
	{
		iLetter = iLetter + 1;
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &UInGameUI::OnTimerCompleted, DelayBetweenLetters, false);
	}
	else // Last letter, animation completed
	{
		bTextCompleted = true;
		bAnimating = false;
	}
}

void UInGameUI::Interact()
{
	if (bAnimating) {
		GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
		bAnimating = false;
		PlayerDialogTextBlock->SetText(FText::FromString(InitialMessage));
		bTextCompleted = true;
	}
	else if (bTextCompleted)
	{
		bTextCompleted = false;

		OnAnimationHideMessageUI();
	}
}
