#pragma once
#include "CoreMinimal.h"
#include "Effects.h"
#include "FireAfterBurnE.generated.h"
UCLASS()
class TRYBETTERAGAIN_API UFireAfterBurnE : public UEffects
{
	GENERATED_BODY()
	int SingleDamage;
	UFireAfterBurnE() ;
	virtual void Apply(float Delta) override;
};