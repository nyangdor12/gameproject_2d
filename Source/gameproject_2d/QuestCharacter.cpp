// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestCharacter.h"
#include "Components/BoxComponent.h"
#include "Hero.h"
#include "HeroController.h"
#include "HeroGM.h"

AQuestCharacter::AQuestCharacter()
{
	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	Trigger->SetupAttachment(RootComponent);
	Trigger->OnComponentBeginOverlap.AddUniqueDynamic(this, &AQuestCharacter::BeginOverlap);
	Trigger->OnComponentEndOverlap.AddUniqueDynamic(this, &AQuestCharacter::EndOverlap);
}

void AQuestCharacter::BeginPlay()
{
	Super::BeginPlay();
	QuestActivated = true;

	SetActorTickEnabled(true);

}

void AQuestCharacter::BeginOverlap(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (PlayerCharacter != nullptr) return;

	AHero* OtherCharacter = Cast<AHero>(OtherActor);

	if (OtherCharacter != nullptr)
	{
		PlayerCharacter = OtherCharacter;
		PlayerCharacter->OnEnterActor(this);
		CPC = Cast<AHeroController>(PlayerCharacter->GetController());
		CPC->OnShowUI(CharacterName);
	
	}
}


void AQuestCharacter::EndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
	if (PlayerCharacter != nullptr)
	{
		PlayerCharacter->OnLeaveActor();
		CPC->OnHideUI();
	}

	PlayerCharacter = nullptr;
}

FName AQuestCharacter::GetName()
{
	return CharacterName;
}

FName AQuestCharacter::GetQuestID()
{
	return QuestID;
}

void AQuestCharacter::OnInteract_Implementation()
{
	// Retrieve info quest from game mode
	AHeroGM* GameMode = Cast<AHeroGM>(GetWorld()->GetAuthGameMode());
	if (GameMode == nullptr) return;

	if (!QuestActivated) return;

	bool Success = false;
	// Find the quest on the game mode
	FQuest Quest = GameMode->FindQuest(QuestID, Success);

	if (!Success) return;


	// Check if player has already accepted the quest
	bool bQuestAccepted = false;
	FQuestItem QuestInfo;
	bQuestAccepted = PlayerCharacter->FindQuest(QuestID, QuestInfo);

	// Quest not accepted, show info quest mark quest as a accepted
	if (!bQuestAccepted)
	{
		CPC->OnShowQuestInfo(Quest);
		PlayerCharacter->AcceptQuest(QuestID);
	}
	else
	{
		// If quest is not completed yet, check if player has the item
		if (!QuestInfo.IsCompleted)
		{
			if (PlayerCharacter->HasItem(Quest.ItemID))
			{
				PlayerCharacter->RemoveItem(Quest.ItemID);
				PlayerCharacter->MarkQuestCompleted(QuestID);

				CPC->OnShowQuestCompleted(Quest.CompleteMessage);
				QuestActivated = false;

			}
			else
			{
				CPC->OnShowQuestInfo(Quest);
			}
		}
		else
		{
			CPC->OnShowQuestInfo(Quest);
		}
	}
}