// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "Interactable.h"
#include "QuestCharacter.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPROJECT_2D_API AQuestCharacter : public APaperZDCharacter, public IInteractable
{
	GENERATED_BODY()


protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "QuestCharacter")
	class UBoxComponent* Trigger;

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "QuestCharacter")
	FName CharacterName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "QuestCharacter")
	FName QuestID;

	bool QuestActivated = false;

protected:
	AQuestCharacter();

	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void EndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);


protected:

	class AHero* PlayerCharacter;
	class AHeroController* CPC;

public:

	FName GetName();
	FName GetQuestID();

	// Interaface
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interact")
	void OnInteract();

	//Actual implementation of the Interact
	void OnInteract_Implementation();

};
