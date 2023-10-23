// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperSpriteActor.h"

#include "Interactable.h"
#include "Openable.h"

#include "Ledge.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPROJECT_2D_API ALedge : public APaperSpriteActor, public IInteractable, public IOpenable
{
	GENERATED_BODY()
	
public:
	UFUNCTION()
	virtual bool CanInteract_Implementation() override {
		return
			IInteractable::CanInteract_Implementation();
	};

	UFUNCTION()
	virtual void PerformInteract_Implementation() override;

	UFUNCTION()
	virtual void Open_Implementation() override;
};
