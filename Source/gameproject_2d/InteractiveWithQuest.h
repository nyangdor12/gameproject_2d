// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractiveBase.h"
#include "InteractiveWithQuest.generated.h"

/**
 * come to think of it, this doesn't need to be an interactive base since i don't need the ui. but this can be an example for 
 * if i want interaction with the dialogue or something
 */
UCLASS()
class GAMEPROJECT_2D_API AInteractiveWithQuest : public AInteractiveBase
{
	GENERATED_BODY()

public:

	void Interact() override;

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "QuestCharacter")
	FName CharacterName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "QuestCharacter")
	FName QuestID;

	bool QuestActivated = false;

protected:
	virtual void BeginPlay() override;

public:
	FName GetCharacterName();
	FName GetQuestID();
};
