#pragma once
#include "CoreMinimal.h"
#include "Effects.h"
#include "FireAuraS.generated.h"
UCLASS()
class TRYBETTERAGAIN_API UFireAuraS : public UEffects
{
	GENERATED_BODY()
	int SingleDamage;
	UFireAuraS();
	virtual void Apply(float Delta) override;
};