#include "FireFireS.h"
#include "CommonAncestor.h"
FireFireS::FireFireS()
{
	BuffCount = 1;
	EffectTime = 2.0f;
	IsPermanent = false;
	IsPositive = true;
	Dispellable = true;
	Name = NameEffects::FireFireS;

}
void FireFireS::Apply(float Delta)
{
	Target->RealA["AttackSpeed"] += BuffCount * 10;
	Target->RealM["CastTime"] /= (1.0f + 0.05*BuffCount);
	Target->RealM["CoolDownTime"] /= 1.0 + 0.04 * BuffCount;
}
void FireFireS::AddEffect(int i)
{
	BuffCount = (Target->SkillLevel[(int32)Skill::FireFire - (int32)Skill::Fire_Start] > BuffCount + i) ? BuffCount + i : Target->SkillLevel[(int32)Skill::FireFire - (int32)Skill::Fire_Start];
	EffectTime = 2.0f;
}