// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractiveBase.h"
#include "InteractiveWithDialogue.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPROJECT_2D_API AInteractiveWithDialogue : public AInteractiveBase
{
	GENERATED_BODY()

public:

	void Interact() override;

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue")
	class UDataTable* Dialogue;

	// Event handle
	UFUNCTION()
	void OnDialogueCompleted();

	bool bIsInteracting = false;
};

