#pragma once
#include "CoreMinimal.h"
#include "Effects.h"
//#include "FireBurnE.generated.h"
//UCLASS()
class TRYBETTERAGAIN_API FireBurnE : public Effects
{
	//GENERATED_BODY()
	int SingleDamage;
	FireBurnE();
	virtual void Apply(float Delta) override;
};