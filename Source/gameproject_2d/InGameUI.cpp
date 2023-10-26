// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameUI.h"
#include "Components/TextBlock.h"

void UInGameUI::SetMessage(const FString& Text)
{
	if (PlayerDialogTextBlock == nullptr) return;

	PlayerDialogTextBlock->SetText(FText::FromString(Text));
}


void UInGameUI::SetCharacterName(const FString& Text)
{
	if (CharacterNameText == nullptr) return;

	CharacterNameText->SetText(FText::FromString(Text));
}