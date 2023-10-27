// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"

//#include "Kismet/GameplayStatics.h"
#include "QuestStructs.h"
#include "Interactable.h"
#include "Hero.generated.h"



UCLASS(Blueprintable)
class GAMEPROJECT_2D_API AHero : public APaperZDCharacter
{
	GENERATED_BODY()
	
protected:

	class AInteractiveBase* CurrentInteractive;

public:

	FORCEINLINE class AInteractiveBase* GetInteractive() { return CurrentInteractive; }


	////////////////// Interactives //////////////////////////////
public:
	void SetInteractiveInRange(class AInteractiveBase* Interactive);
	void ClearInteractiveInRange(class AInteractiveBase* Interactive);

	////////////////// Interactives //////////////////////////////

	/////////////////////// Quest ///////////////////////////////
protected:


	TArray<FQuestItem> QuestList;

public:
	bool FindQuest(FName QuestID, FQuestItem& Quest);

	void AcceptQuest(FName QuestID);

	void MarkQuestCompleted(FName QuestID);

public:

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Events")
	void OnShowQuestInfo(FQuest Quest);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Events")
	void OnShowQuestCompleted(const FText& Message);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Events")
	void OnShowUpdatedQuestList(const TArray<FText>& QuestTextList);

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Events")
	void OnShowUI(FName Character);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Events")
	void OnHideUI();

protected:

	void UpdateAndShowQuestList();

public:

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Quest")
	bool HasItem(FName ItemID);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Quest")
	void RemoveItem(FName ItemID);

	/////////////////////// Quest ///////////////////////////////
};
