// Fill out your copyright notice in the Description page of Project Settings.


#include "Ledge.h"

void ALedge::PerformInteract_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT("The door refuses to budge. Perhaps there is a hidden switch nearby ? "));
}

void ALedge::Open_Implementation()
{
	AddActorLocalOffset(FVector(0, 0, 200));
}