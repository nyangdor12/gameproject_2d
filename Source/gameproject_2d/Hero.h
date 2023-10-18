// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"

//#include "Kismet/GameplayStatics.h"
//#include "HeroController.h"

#include "Hero.generated.h"



UCLASS(Blueprintable)
class GAMEPROJECT_2D_API AHero : public APaperZDCharacter
{
	GENERATED_BODY()
	
public:

	//UPROPERTY(BlueprintReadOnly)
	//APlayerController* PC_Ref;

	//AHero();
protected:
	// Called when the game starts or when spawned
	//virtual void BeginPlay() override;

private:
};
