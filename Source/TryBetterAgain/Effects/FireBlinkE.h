#pragma once
#include "CoreMinimal.h"
#include "Effects.h"
#include "FireBlinkE.generated.h"
UCLASS()
class TRYBETTERAGAIN_API UFireBlinkE : public UEffects
{
	GENERATED_BODY()
	int SingleDamage;
	UFireBlinkE();
	virtual void Apply(float Delta) override;
};