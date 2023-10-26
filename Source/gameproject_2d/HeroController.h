// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "HeroController.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPROJECT_2D_API AHeroController : public APlayerController
{
	GENERATED_BODY()

public:

	AHeroController();
	virtual void BeginPlay() override;

	///// UI //////
protected:

	UPROPERTY(BlueprintReadWrite, Category = "Player UI")
	class UInGameUI* InGameUI;

	TSubclassOf<class UUserWidget> InGameUIClass;


public:

	FORCEINLINE UInGameUI* GetUI() { return InGameUI; };
};
