// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "QuestStructs.h"
#include "HeroController.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPROJECT_2D_API AHeroController : public APlayerController
{
	GENERATED_BODY()
protected:

	// Reference to the pawn
	class AHero* MyCharacter;

public:

	AHeroController();
	virtual void BeginPlay() override;

protected:

	virtual void SetupInputComponent() override;

protected:

	UFUNCTION(BlueprintCallable, Category = "Inputs")
	void Interact();

	UFUNCTION(BlueprintCallable, Category = "Inputs")
	void Action();

	UFUNCTION(BlueprintCallable, Category = "Inputs")
	void OnKeyUp();

	UFUNCTION(BlueprintCallable, Category = "Inputs")
	void OnKeyDown();

	///// UI //////
protected:

	UPROPERTY(BlueprintReadWrite, Category = "Player UI")
	class UInGameUI* InGameUI;

	TSubclassOf<class UUserWidget> InGameUIClass;

	// Event handle
	UFUNCTION()
	void OnIntroDialogueCompleted();

public:

	FORCEINLINE UInGameUI* GetUI() { return InGameUI; };

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue")
	class UDataTable* IntroDialogue;

public:

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Events")
	void OnShowQuestInfo(FQuest Quest);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Events")
	void OnShowQuestCompleted(const FText& Message);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Events")
	void OnShowUpdatedQuestList(const TArray<FText>& QuestTextList);

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Events")
	void OnShowUI(FName Char);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Events")
	void OnHideUI();
};
