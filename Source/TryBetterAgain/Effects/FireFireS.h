#pragma once
#include "CoreMinimal.h"
#include "Effects.h"
//#include "FireFireS.generated.h"
//UCLASS()
class TRYBETTERAGAIN_API FireFireS : public Effects
{
	//GENERATED_BODY()
public:
	int BuffCount;
	FireFireS();
	virtual void Apply(float Delta) override;
	void AddEffect(int i=1);
};