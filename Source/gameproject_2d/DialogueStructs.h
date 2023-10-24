#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "gameproject_2d.h"
#include "DialogueStructs.generated.h"

USTRUCT(BlueprintType)
struct GAMEPROJECT_2D_API FMessageOptions
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText OptionText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 AnswerIndex;

};


USTRUCT(BlueprintType)
struct GAMEPROJECT_2D_API FDialogNPC : public FTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName CharacterName; // Name of the character to display

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FText> Messages; // Text	

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FMessageOptions> MessageOptions; // Options to display

};