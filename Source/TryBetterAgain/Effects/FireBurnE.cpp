#include "FireBurnE.h"
#include "CommonAncestor.h"

UFireBurnE::UFireBurnE()
{
	DebuffCount = 1;
	EffectTime = 2.0f;
	IsPermanent = false;
	IsPositive = false;
	Dispellable = true;
	Name = NameEffects::FireBurnE;
}
void UFireBurnE::IncrementEffect(int i)
{
	DebuffCount = (Target->SkillLevel[(int32)Skill::FireBurn - (int32)Skill::Fire_Start] > DebuffCount + i) ? DebuffCount + i : Target->SkillLevel[(int32)Skill::FireBurn - (int32)Skill::Fire_Start];
	EffectTime = 2.0f;
}
void UFireBurnE::Apply(float Delta)
{
	TimeSum += Delta;
	if (TimeSum >= 0.25f)
	{
		Target->RealA["TickDamage"] += DebuffCount;
		UE_LOG(LogTemp, Warning, TEXT("Let's go %d, ,%d"), Target->RealA["TickDamage"], Target->Health);
		TimeSum -= 0.25;
	}
	EffectTime -= Delta;
}