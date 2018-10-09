#pragma once
#include "CoreMinimal.h"
#include "Effects.h"
//#include "FireAfterBurnE.generated.h"
//UCLASS()
class TRYBETTERAGAIN_API FireAuraS : public Effects
{
	//GENERATED_BODY()
	int SingleDamage;
	FireAuraS();
	virtual void Apply(float Delta) override;
};