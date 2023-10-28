// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractiveBase.generated.h"

UCLASS()
class GAMEPROJECT_2D_API AInteractiveBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractiveBase();
protected:

	// Components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "InteractiveComponent")
	class USceneComponent* RootScene;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "InteractiveComponent")
	class UBoxComponent* InteractiveCollision;

protected:

	class AHero* CurrentCharacter;

	class AHeroController* CurrentPlayerController;


protected:

	UFUNCTION()
	virtual void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void EndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);


protected:

	bool bIsEnabled;


public:

	virtual void BeginPlay() override;

	virtual void SetEnable(bool Enable);

	virtual void Interact();

};
