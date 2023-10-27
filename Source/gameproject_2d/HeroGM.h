// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "QuestStructs.h"
#include "HeroGM.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPROJECT_2D_API AHeroGM : public AGameModeBase
{
	GENERATED_BODY()


protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Quest System")
	class UQuestData* QuestDatabase;

public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Quest System")
	FQuest FindQuest(FName QuestID, bool& Success);

	FQuest FindQuest_Implementation(FName QuestID, bool& Success);



};
