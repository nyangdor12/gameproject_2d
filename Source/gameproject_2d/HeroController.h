// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InGameUI.h"
#include "HeroController.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPROJECT_2D_API AHeroController : public APlayerController
{
	GENERATED_BODY()

	//stealthgame youtuber
protected:
	AHeroController();

	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void SetupInputComponent() override;

	UPROPERTY(BlueprintReadWrite, Category="Player UI")
	class UInGameUI* InGameUI = nullptr;

	TSubclassOf<class UUserWidget> InGameUIClass;

	UFUNCTION(BlueprintCallable, Category = "Inputs")
	void UI_Interact();

	UFUNCTION(BlueprintCallable, Category = "Inputs")
	void OnKeyUp();

	UFUNCTION(BlueprintCallable, Category = "Inputs")
	void OnKeyDown();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue")
	class UDataTable* IntroDialogue;
public:

	//FORCEINLINE UInGameUI* GetUI() { return InGameUI; };
};
