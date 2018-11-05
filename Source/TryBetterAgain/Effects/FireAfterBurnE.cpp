#include "FireAfterBurnE.h"
#include "CommonAncestor.h"
UFireAfterBurnE::UFireAfterBurnE()
{
	EffectTime = 2.0f;
	IsPermanent = false;
	IsPositive = false;
	Dispellable = true;
	Name = NameEffects::FireAfterBurnE;
}
void UFireAfterBurnE::Apply(float Delta)
{
	EffectTime -= Delta;
	LastExplosionTime += Delta;
	if (LastExplosionTime >= 0.25f)
	{
		LastExplosionTime -= 0.25;
		Target->RealA["TickDamage"] += SingleDamage;
	}
}
