#pragma once
#include "Interactable.generated.h"

/** */
UINTERFACE(Blueprintable)
class GAMEPROJECT_2D_API UInteractable : public UInterface
{
	GENERATED_BODY()
};

/** */
class GAMEPROJECT_2D_API IInteractable
{
	GENERATED_BODY()
public:
	virtual FString GetTestName();
};