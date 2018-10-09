#pragma once
#include "CoreMinimal.h"
#include "Effects.h"
//#include "FireAfterBurnE.generated.h"
//UCLASS()
class TRYBETTERAGAIN_API FireAfterBurnE : public Effects
{
	//GENERATED_BODY()
	int SingleDamage;
	FireAfterBurnE() ;
	virtual void Apply(float Delta) override;
};