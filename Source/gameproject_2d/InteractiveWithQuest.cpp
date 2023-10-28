#include "InteractiveWithQuest.h"
#include "HeroGM.h"
#include "Hero.h"
#include "HeroController.h"

void AInteractiveWithQuest::BeginPlay()
{
	Super::BeginPlay();
	QuestActivated = true;
}

void AInteractiveWithQuest::Interact()
{
	// Retrieve info quest from game mode
	AHeroGM* GameMode = Cast<AHeroGM>(GetWorld()->GetAuthGameMode());
	if (GameMode == nullptr) return;

	if (!QuestActivated) return;

	bool Success = false;
	// Find the quest on the game mode, to see if it was already accepted
	FQuest Quest = GameMode->FindQuest(QuestID, Success);

	if (!Success) return;


	// Check if player has already accepted the quest
	bool bQuestAccepted = false;
	FQuestItem QuestInfo;
	bQuestAccepted = CurrentCharacter->FindQuest(QuestID, QuestInfo);

	// Quest not accepted, show info quest mark quest as a accepted
	if (!bQuestAccepted)
	{
		CurrentPlayerController->OnShowQuestInfo(Quest);
		CurrentCharacter->AcceptQuest(QuestID);
	}
	else
	{
		// If quest is not completed yet, check if player has the item
		if (!QuestInfo.IsCompleted)
		{
			if (CurrentCharacter->HasItem(Quest.ItemID))
			{
				CurrentCharacter->RemoveItem(Quest.ItemID);
				CurrentCharacter->MarkQuestCompleted(QuestID);

				CurrentPlayerController->OnShowQuestCompleted(Quest.CompleteMessage);
				QuestActivated = false;

			}
			else
			{
				CurrentPlayerController->OnShowQuestInfo(Quest);
			}
		}
		else
		{
			CurrentPlayerController->OnShowQuestInfo(Quest);
		}
	}
}


FName AInteractiveWithQuest::GetCharacterName()
{
	return CharacterName;
}

FName AInteractiveWithQuest::GetQuestID()
{
	return QuestID;
}