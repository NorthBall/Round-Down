#pragma once
#include "CoreMinimal.h"
#include "Effects.h"
#include "FireFireS.generated.h"
UCLASS(Blueprintable)
class TRYBETTERAGAIN_API UFireFireS : public UEffects
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, Category = Effects)
		TSubclassOf<class AActor> VRepr;
	AActor * Model;
	int BuffCount;
	UFireFireS();
	virtual void Apply(float Delta) override;
	void IncrementEffect(int i=1);
};