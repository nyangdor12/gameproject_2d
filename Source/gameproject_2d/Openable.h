#pragma once
#include "Openable.generated.h"

/** */
UINTERFACE(Blueprintable)
class GAMEPROJECT_2D_API UOpenable : public UInterface
{
	GENERATED_BODY()
};

/** */
class GAMEPROJECT_2D_API IOpenable
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Openable)
	void Open();
};