// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractiveBase.h"
#include "Components/BoxComponent.h"
#include "Hero.h"
#include "HeroController.h"

// Sets default values
AInteractiveBase::AInteractiveBase()
{
	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = RootScene;

	InteractiveCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("InteractiveCollision"));
	InteractiveCollision->SetupAttachment(RootComponent);

	InteractiveCollision->OnComponentBeginOverlap.AddDynamic(this, &AInteractiveBase::BeginOverlap);
	InteractiveCollision->OnComponentEndOverlap.AddDynamic(this, &AInteractiveBase::EndOverlap);

	PrimaryActorTick.bCanEverTick = true;
}

void AInteractiveBase::BeginPlay()
{
	Super::BeginPlay();

	bIsEnabled = true;

}


void AInteractiveBase::BeginOverlap(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep,
	const FHitResult& SweepResult)
{
	if (!bIsEnabled) return;

	CurrentCharacter = Cast<AHero>(OtherActor);

	if (CurrentCharacter)
	{
		CurrentPlayerController = Cast<AHeroController>(CurrentCharacter->GetController());

		CurrentCharacter->SetInteractiveInRange(this);
	}
}

void AInteractiveBase::EndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (!bIsEnabled) return;

	CurrentCharacter = Cast<AHero>(OtherActor);

	if (CurrentCharacter)
	{
		CurrentCharacter->ClearInteractiveInRange(this);

		CurrentPlayerController = nullptr;
	}
}


void AInteractiveBase::SetEnable(bool Enable)
{
	bIsEnabled = Enable;

	if (bIsEnabled)
	{
		// Only used for spatial queries (raycasts, sweeps, and overlaps).
		InteractiveCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	}
	else
	{
		//Remove collision completely
		InteractiveCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
}


void AInteractiveBase::Interact()
{
	if (!bIsEnabled) return;
}


