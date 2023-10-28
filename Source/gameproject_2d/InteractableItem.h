// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperSpriteActor.h"
#include "Interactable.h"
#include "InteractableItem.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPROJECT_2D_API AInteractableItem : public APaperSpriteActor, public IInteractable
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "BasicInteractive")
	class UBoxComponent* Trigger;

	class AHero* PlayerCharacter;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "BasicInteractive")
	FName InteractableName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "BasicInteractive")
	FName QuestID;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "BasicInteractive")
	bool QuestActivated;

public:

	AInteractableItem();

protected:

	UFUNCTION()
	virtual void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
		bool bFromSweep, const FHitResult& SweepResult);

	virtual void OnPlayerBeginOverlap();

	UFUNCTION()
	virtual void EndOverlap(UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	virtual void OnPlayerEndOverlap();

	//////////// INTERFACE IInteractable //////////////////
public:

	FName GetName();

	// Interaface
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interact")
	void OnInteract();

	//Actual implementation of the Interact event
	void OnInteract_Implementation();

	FName GetQuestID();
	
};
