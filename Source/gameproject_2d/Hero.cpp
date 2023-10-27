// Fill out your copyright notice in the Description page of Project Settings.


#include "Hero.h"
#include "HeroGM.h"

void AHero::SetInteractiveInRange(class AInteractiveBase* Interactive)
{
	
	if (Interactive != nullptr)
	{
		CurrentInteractive = Interactive;


	}
}

void AHero::ClearInteractiveInRange(class AInteractiveBase* Interactive)
{
	if (Interactive != nullptr)
	{
		CurrentInteractive = nullptr;
	}
}

bool AHero::FindQuest(FName QuestID, FQuestItem& Quest)
{
	for (int i = 0; i < QuestList.Num(); i++)
	{
		if (QuestList[i].QuestID == QuestID)
		{
			Quest = QuestList[i];
			return true;
		}
	}
	return false;
}

void AHero::AcceptQuest(FName QuestID)
{
	bool QuestFound = false;
	for (int i = 0; i < QuestList.Num(); i++)
	{
		if (QuestList[i].QuestID == QuestID)
		{
			QuestFound = true;
			break;
		}
	}

	if (!QuestFound)
	{
		FQuestItem NewQuest;
		NewQuest.QuestID = QuestID;
		NewQuest.IsCompleted = false;
		QuestList.Add(NewQuest);

		UpdateAndShowQuestList();
	}
}

void AHero::MarkQuestCompleted(FName QuestID)
{
	for (int i = 0; i < QuestList.Num(); i++)
	{
		if ((QuestList[i].QuestID == QuestID) && (!QuestList[i].IsCompleted))
		{
			QuestList[i].IsCompleted = true;
			break;
		}
	}

	UpdateAndShowQuestList();
}

void AHero::UpdateAndShowQuestList()
{
	// Prepare list of quest, to show on the UI
	AHeroGM* GameMode = Cast<AHeroGM>(GetWorld()->GetAuthGameMode());

	if (GameMode != nullptr)
	{
		TArray<FText> QuestTextList;
		for (int i = 0; i < QuestList.Num(); i++)
		{
			if (!QuestList[i].IsCompleted)
			{
				bool Success = false;
				// Find the quest on the game mode
				FQuest Quest = GameMode->FindQuest(QuestList[i].QuestID, Success);

				if (Success)
				{
					QuestTextList.Add(Quest.SortDescription);
				}
			}
		}

		OnShowUpdatedQuestList(QuestTextList);
	}
}
