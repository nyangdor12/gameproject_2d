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
};
