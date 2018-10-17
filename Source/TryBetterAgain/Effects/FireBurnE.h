#pragma once
#include "CoreMinimal.h"
#include "Effects.h"
#include "FireBurnE.generated.h"
UCLASS()
class TRYBETTERAGAIN_API UFireBurnE : public UEffects
{
	GENERATED_BODY()
public:
	int DebuffCount;
	float TimeSum;
	UFireBurnE();
	void IncrementEffect(int32 i = 1);
	virtual void Apply(float Delta) override;
};