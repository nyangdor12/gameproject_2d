// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperSpriteActor.h"

#include "Interactable.h"

#include "Lever.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPROJECT_2D_API ALever : public APaperSpriteActor, public IInteractable
{
	GENERATED_BODY()

public:
	ALever();
	virtual bool CanInteract_Implementation() override;
	virtual void PerformInteract_Implementation() override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	AActor* DoorToOpen;
private:
	bool HasBeenPushed;
};
