// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableItem.h"
#include "Hero.h"
#include "HeroController.h"
#include "Components/BoxComponent.h"

AInteractableItem::AInteractableItem()
{

	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	Trigger->SetupAttachment(RootComponent);

	Trigger->OnComponentBeginOverlap.AddUniqueDynamic(this, &AInteractableItem::BeginOverlap);
	Trigger->OnComponentEndOverlap.AddUniqueDynamic(this, &AInteractableItem::EndOverlap);

	PrimaryActorTick.bCanEverTick = false;
}


void AInteractableItem::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	PlayerCharacter = Cast<AHero>(OtherActor);

	if (PlayerCharacter != nullptr)
	{
		PlayerCharacter->OnEnterActor(this);

		OnPlayerBeginOverlap();
	}
}

void AInteractableItem::OnPlayerBeginOverlap()
{
	if (PlayerCharacter != nullptr)
	{
		Cast<AHeroController>(PlayerCharacter->GetController())->OnShowUI(InteractableName);
	}
}


void AInteractableItem::EndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (PlayerCharacter != nullptr)
	{
		PlayerCharacter->OnLeaveActor();

		OnPlayerEndOverlap();
	}
}

void AInteractableItem::OnPlayerEndOverlap()
{
	if (PlayerCharacter != nullptr)
	{
		Cast<AHeroController>(PlayerCharacter->GetController())->OnHideUI();
	}
}

FName AInteractableItem::GetName()
{
	return InteractableName;
}

void AInteractableItem::OnInteract_Implementation()
{
	//in the blueprint
}

FName AInteractableItem::GetQuestID()
{
	return QuestID;
}
