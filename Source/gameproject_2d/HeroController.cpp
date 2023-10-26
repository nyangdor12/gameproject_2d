// Fill out your copyright notice in the Description page of Project Settings.


#include "HeroController.h"
#include "InGameUI.h"

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


	// Create InGameUI and add it to the viewpoert
	if (InGameUIClass != nullptr)
	{
		InGameUI = CreateWidget<UInGameUI>(this, InGameUIClass);
	}

	if (InGameUI != nullptr)
	{
		InGameUI->AddToViewport();


		// OLD TEST
		InGameUI->SetMessage("HELLO WORLD!");
		InGameUI->SetCharacterName("Blue Robot");
		InGameUI->OnAnimationShowMessageUI();
	}
}
