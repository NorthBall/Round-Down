#pragma once
#include "CoreMinimal.h"
#include "Effects.h"
//#include "FireAfterBurnE.generated.h"
//UCLASS()
class TRYBETTERAGAIN_API FireAuraE : public Effects
{
	//GENERATED_BODY()
	int SingleDamage;
	FireAuraE();
	virtual void Apply(float Delta) override;
};