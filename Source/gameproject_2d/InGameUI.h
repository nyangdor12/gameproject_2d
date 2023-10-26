// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DialogueStructs.h"
#include "InGameUI.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPROJECT_2D_API UInGameUI : public UUserWidget
{
	GENERATED_BODY()

protected:
	
	UPROPERTY(EditAnywhere, Category = "UI Message Settings")
	float DelayBetweenLetters = 0.3f;

protected:

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* PlayerDialogTextBlock;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* CharacterNameText;


public:

	UFUNCTION(BlueprintImplementableEvent, Category = "Animation Events")
	void OnAnimationShowMessageUI();

	UFUNCTION(BlueprintImplementableEvent, Category = "Animation Events")
	void OnAnimationHideMessageUI();


	UFUNCTION(BlueprintImplementableEvent, Category = "Animation Events")
	void OnShowMessage();

	UFUNCTION(BlueprintImplementableEvent, Category = "Animation Events")
	void OnHideMessage();

public:

	UFUNCTION(BlueprintImplementableEvent, Category = "Animation Events")
	void OnResetOptions();

	UFUNCTION(BlueprintImplementableEvent, Category = "Animation Events")
	void OnHighLightOption(int32 Option);

	UFUNCTION(BlueprintImplementableEvent, Category = "Animation Events")
	void OnSetOption(int32 Option, const FText& OptionText);


public:

	void SetMessage(const FString& Text);

	void SetCharacterName(const FString& Text);

	void AnimateMessage(const FString& Text);

	void Interact();

	void InitializeDialogue(class UDataTable* DialogueTable);

	void OnSelectUpOption();

	void OnSelectDownOption();

private:

	FTimerHandle TimerHandle;

	UFUNCTION()
	void OnTimerCompleted();

	UFUNCTION()
	void OnAnimationTimerCompleted();

	FString InitialMessage;

	FString OutputMessage;

	int32 iLetter;

private:

	int32 CurrentState = 0; // 0 = None, 1 = Animating, 2 == Text completed

	int32 SelectectedOption;

	TArray<FDialogNPC*> Dialogue;

	int32 MessageIndex;

	int32 RowIndex;
};
