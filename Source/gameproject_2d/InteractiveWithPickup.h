// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractiveBase.h"
#include "InteractiveWithPickup.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPROJECT_2D_API AInteractiveWithPickup : public AInteractiveBase
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Interactive")
	void Interact() override;
};
