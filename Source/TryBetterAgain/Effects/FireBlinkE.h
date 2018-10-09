#pragma once
#include "CoreMinimal.h"
#include "Effects.h"
//#include "FireAfterBurnE.generated.h"
//UCLASS()
class TRYBETTERAGAIN_API FireBlinkE : public Effects
{
	//GENERATED_BODY()
	int SingleDamage;
	FireBlinkE();
	virtual void Apply(float Delta) override;
};