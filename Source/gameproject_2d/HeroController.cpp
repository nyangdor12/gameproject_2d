// Fill out your copyright notice in the Description page of Project Settings.


#include "HeroController.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/DataTable.h"



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


	//Create InGmaeUI and add it to the viewport
	if (InGameUIClass != nullptr) {
		InGameUI = CreateWidget<UInGameUI>(this, InGameUIClass);
	}
	if (InGameUI != nullptr) {
		InGameUI->AddToViewport();
		
		//testing the ui and the event
		//InGameUI->SetMessage("Hello");
		//InGameUI->SetCharacterName("Robot");
		//InGameUI->OnAnimationShowMessageUI();
		//InGameUI->AnimateMessage("Blue Robot", "This is an animated text letter by letter");

		if (IntroDialogue != nullptr) {
			SetCinematicMode(true, true, true);
			InGameUI->InitializeDialogue(IntroDialogue);
		}
	}
}

void AHeroController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAction("Dialogue", IE_Pressed, this, &AHeroController::UI_Interact);

	InputComponent->BindAction("KeyUp", IE_Pressed, this, &AHeroController::OnKeyUp).bConsumeInput = false;
	InputComponent->BindAction("KeyDown", IE_Pressed, this, &AHeroController::OnKeyDown).bConsumeInput = false;
}

void AHeroController::UI_Interact()
{
	if (InGameUI != nullptr) {
		InGameUI->UI_Interact();
	}
}

void AHeroController::OnKeyUp()
{
	if (InGameUI != nullptr) {
		InGameUI->OnSelectUpOption();
	}
}

void AHeroController::OnKeyDown()
{
	if (InGameUI != nullptr) {
		InGameUI->OnSelectDownOption();
	}
}
