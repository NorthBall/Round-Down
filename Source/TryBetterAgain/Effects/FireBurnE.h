#pragma once
#include "CoreMinimal.h"
#include "Effects.h"
#include "FireBurnE.generated.h"
UCLASS(Blueprintable)
class TRYBETTERAGAIN_API UFireBurnE : public UEffects
{
	GENERATED_BODY()
public:
	~UFireBurnE();
	virtual void DeleteSelf() override;
	UPROPERTY(EditDefaultsOnly, Category = Effects)
		TSubclassOf<class AActor> VRepr;
	AActor *Model;
	int DebuffCount;
	float TimeSum;
	UFireBurnE();
	void IncrementEffect(int32 i = 1);
	virtual void Apply(float Delta) override;
};