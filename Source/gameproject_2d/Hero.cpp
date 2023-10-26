// Fill out your copyright notice in the Description page of Project Settings.


#include "Hero.h"

void AHero::SetInteractiveInRange(class AInteractiveBase* Interactive)
{
	
	if (Interactive != nullptr)
	{
		CurrentInteractive = Interactive;
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red,
			FString::Printf(TEXT("current interactive is set")));


	}
}

void AHero::ClearInteractiveInRange(class AInteractiveBase* Interactive)
{
	if (Interactive != nullptr)
	{
		CurrentInteractive = nullptr;
	}
}
