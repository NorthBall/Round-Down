#pragma once
#include "CoreMinimal.h"
#include "Effects.h"
#include "FireAuraE.generated.h"
UCLASS()
class TRYBETTERAGAIN_API UFireAuraE : public UEffects
{
	GENERATED_BODY()
	int SingleDamage;
	UFireAuraE();
	virtual void Apply(float Delta) override;
};