#pragma once
#include "Damageable.generated.h"

/** */
UINTERFACE(Blueprintable)
class GAMEPROJECT_2D_API UDamageable : public UInterface
{
	GENERATED_BODY()
};

/** */
class GAMEPROJECT_2D_API IDamageable
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = Damage)
	void InflictDamage();
};