#pragma once
#include "CoreMinimal.h"
#include "gameproject_2d.h"
#include "Engine/DataAsset.h"
#include "QuestStructs.generated.h"

USTRUCT(BlueprintType)
struct GAMEPROJECT_2D_API FQuest
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Quest")
	FName CharacterName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Quest")
	FName QuestID;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Quest")
	FText Message;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Quest")
	FText SortDescription;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Quest")
	FText CompleteMessage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Quest")
	FName ItemID;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Quest")
	UTexture2D* ItemQuestTexture;

};


UCLASS(BlueprintType)
class GAMEPROJECT_2D_API UQuestData : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Quest")
	TArray<FQuest> QuestData;
};


USTRUCT(BlueprintType)
struct GAMEPROJECT_2D_API FQuestItem
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Quest")
	FName QuestID;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Quest")
	bool IsCompleted;
};