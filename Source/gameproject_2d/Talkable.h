#pragma once
#include "Talkable.generated.h"

/** */
UINTERFACE(Blueprintable)
class GAMEPROJECT_2D_API UTalkable : public UInterface
{
	GENERATED_BODY()
};

/** */
class GAMEPROJECT_2D_API ITalkable
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Talk)
	void Talk();
};