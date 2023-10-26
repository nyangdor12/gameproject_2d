// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractiveWithDialogue.h"
#include "HeroController.h"
#include "InGameUI.h"

void AInteractiveWithDialogue::Interact()
{
	Super::Interact();

	if (bIsInteracting)
	{
		return;
	}

	if ((CurrentPlayerController != nullptr) && (Dialogue != nullptr))
	{
		bIsInteracting = true;

		// Lock the player input
		CurrentPlayerController->SetCinematicMode(true, true, true);

		// Initialize dialogue
		CurrentPlayerController->GetUI()->InitializeDialogue(Dialogue);

		// Subscribe to the event dialogue completed
		CurrentPlayerController->GetUI()->OnDialogueCompleted.AddDynamic(this, &AInteractiveWithDialogue::OnDialogueCompleted);
	}

}

void AInteractiveWithDialogue::OnDialogueCompleted()
{
	if (CurrentPlayerController != nullptr)
	{
		CurrentPlayerController->SetCinematicMode(false, true, true);

		CurrentPlayerController->GetUI()->OnDialogueCompleted.RemoveDynamic(this, &AInteractiveWithDialogue::OnDialogueCompleted);
	}

	bIsInteracting = false;
}
