// Fill out your copyright notice in the Description page of Project Settings.


#include "Lever.h"
#include "Openable.h"

ALever::ALever()
{
	HasBeenPushed = false;
	DoorToOpen = nullptr;
}

bool ALever::CanInteract_Implementation()
{
	return !HasBeenPushed;
}
void ALever::PerformInteract_Implementation()
{
	HasBeenPushed = true;
	if (DoorToOpen->GetClass() -> ImplementsInterface(UOpenable::StaticClass()))
	{
		IOpenable::Execute_Open(DoorToOpen);
	}
}