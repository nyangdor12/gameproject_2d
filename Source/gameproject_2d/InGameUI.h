// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
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

	void SetMessage(const FString& Text);

	void SetCharacterName(const FString& Text);

	void AnimateMessage(const FString& Name, const FString& Text);

	void Interact();

private:

	FTimerHandle TimerHandle;

	UFUNCTION()
	void OnTimerCompleted();

	bool bAnimating = false;
	bool bTextCompleted = false;

	FString InitialMessage;

	FString OutputMessage;

	int32 iLetter;
};
