// Fill out your copyright notice in the Description page of Project Settings.


#include "HeroController.h"
#include "InGameUI.h"
#include "Hero.h"
#include "InteractiveBase.h"

AHeroController::AHeroController()
{
	static ConstructorHelpers::FClassFinder<UUserWidget> InGameMenuBpClass(TEXT("'/Game/Blueprints/Hero/UI/Dialogue/WB_InGameUI'"));
	if (InGameMenuBpClass.Class != nullptr) {
		InGameUIClass = InGameMenuBpClass.Class;
	}

}

void AHeroController::BeginPlay()
{
	Super::BeginPlay();

	// Get reference to the character controllerd by this player controller
	APawn* const pawn = GetPawn();

	if (pawn != nullptr)
	{
		MyCharacter = Cast<AHero>(pawn);
	}

	// Create InGameUI and add it to the viewpoert
	if (InGameUIClass != nullptr)
	{
		InGameUI = CreateWidget<UInGameUI>(this, InGameUIClass);
	}

	if (InGameUI != nullptr)
	{
		InGameUI->AddToViewport();

		
		
		// OLD TEST
		//InGameUI->SetMessage("HELLO WORLD!");
		//InGameUI->SetCharacterName("Blue Robot");
		//InGameUI->OnAnimationShowMessageUI();
		//LESS OLD TEST
		//InGameUI->AnimateMessage("Blue Robot", "This is an animated text letter by letter");

		if (IntroDialogue != nullptr)
		{
			SetCinematicMode(true, true, true);
			InGameUI->InitializeDialogue(IntroDialogue);
			// Subscribe to the event
			InGameUI->OnDialogueCompleted.AddDynamic(this, &AHeroController::OnIntroDialogueCompleted);
		}
	}
}

void AHeroController::OnIntroDialogueCompleted()
{
	if (InGameUI != nullptr)
	{
		InGameUI->OnDialogueCompleted.RemoveDynamic(this, &AHeroController::OnIntroDialogueCompleted);
	}
	SetCinematicMode(false, true, true);
}

void AHeroController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("Interact", IE_Pressed, this, &AHeroController::Interact);
	InputComponent->BindAction("Interact", IE_Pressed, this, &AHeroController::Action).bConsumeInput = false;
	InputComponent->BindAction("KeyUp", IE_Pressed, this, &AHeroController::OnKeyUp).bConsumeInput = false;
	InputComponent->BindAction("KeyDown", IE_Pressed, this, &AHeroController::OnKeyDown).bConsumeInput = false;

}

void AHeroController::Interact()
{
	if ((MyCharacter != nullptr) && (MyCharacter->GetInteractive() != nullptr))
	{
		MyCharacter->GetInteractive()->Interact();
	}

	if (InGameUI != nullptr)
	{
		InGameUI->Interact();
	}	
}

void AHeroController::Action()
{
	if (MyCharacter != nullptr)
	{
		MyCharacter->Action();
	}
}

void AHeroController::OnKeyUp()
{
	if (InGameUI != nullptr)
	{
		InGameUI->OnSelectUpOption();
	}
}

void AHeroController::OnKeyDown()
{
	if (InGameUI != nullptr)
	{
		InGameUI->OnSelectDownOption();
	}
}
