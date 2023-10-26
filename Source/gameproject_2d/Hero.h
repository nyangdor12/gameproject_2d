// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"

//#include "Kismet/GameplayStatics.h"
//#include "HeroController.h"
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
};
