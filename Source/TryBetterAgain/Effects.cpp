// Fill out your copyright notice in the Description page of Project Settings.

#include "Effects.h"

Effects::Effects()
{
	IsVisual = false;
	IsPermanent = false;
	IsSingle = true;
	EffectTime = 0.0f;
	IsPositive = true;
}

Effects::~Effects()
{
}
void Effects::Apply(float Delta)
{
	if (!IsPermanent) EffectTime -= Delta;
}
/*void Effects::NullifyStats()
{
	//health and mana
	 MaxHealthA = 0;
	 MaxHealthM=1.0f;
	 MaxManaA=0;
	 MaxManaM = 1.0f;
	//attack
	 AttackDamageA=0;
	 AttackDamageM = 1.0f;
	 AttackSpeedA=0;
	 AttackSpeedM = 1.0f;
	 PreAttack=0.0f;
	 AttackRangeA = 0;
	 MeleeAttackRangeA = 0;
	 AttackRangeM= 1.0f;
				  //Magic
	 MagicPowerA=0;
	 MagicPowerM = 1.0f;
	 MagicRangeA=0;
	 MagicRangeM = 1.0f;
	 CastTimeA=0;
	 CastTimeM = 1.0f;
	 CoolDownTimeA=0;
	 CoolDownTimeM = 1.0f;
	//Armor&&resist
	 ArmorA=0;
	 ArmorM = 1.0f;
	 NegateArmorA=0;
	 NegateArmorM= 1.0f;
	 PhysicMultiplierM = 1.0f;
	 MagicMultiplierM = 1.0f;
	//base stats
	 RedStA=0;
	 GreenStA=0;
	 BlueStA=0;
	 RedStM = 1.0f;
	 GreenStM = 1.0f;
	 BlueStM = 1.0f;
	 //health and mana
	 TickHealthA = 0;
	 TickHealthM = 1.0f;
	 TickPHealthA = 0;
	 TickMHealthA = 0;
	 TickMaxHealthA = 0;
	 TickMaxHealthM = 1.0f;
	 TickManaA = 0;
	 TickManaM = 1.0f;
	 TickMaxManaA = 0;
	 TickMaxManaM = 1.0f;
	 //attack
	 TickAttackDamageA = 0;
	 TickAttackDamageM = 1.0f;
	 TickAttackSpeedA = 0;
	 TickAttackSpeedM = 1.0f;
	 TickPreAttack = 0.0f;
	 TickAttackRangeA = 0;
	 TickMeleeAttackRangeA = 0;
	 TickAttackRangeM = 1.0f;
	 //Magic
	 TickMagicPowerA = 0;
	 TickMagicPowerM = 1.0f;
	 TickMagicRangeA = 0;
	 TickMagicRangeM = 1.0f;
	 TickCastTimeA = 0;
	 TickCastTimeM = 1.0f;
	 TickCoolDownTimeA = 0;
	 TickCoolDownTimeM = 1.0f;
	 //Armor&&resist
	 TickArmorA = 0;
	 TickArmorM = 1.0f;
	 TickNegateArmorA = 0;
	 TickNegateArmorM = 1.0f;
	 TickPhysicMultiplierM = 1.0f;
	 TickMagicMultiplierM = 1.0f;
	 //base stats
	 TickRedStA = 0;
	 TickGreenStA = 0;
	 TickBlueStA = 0;
	 TickRedStM = 1.0f;
	 TickGreenStM = 1.0f;
	 TickBlueStM = 1.0f;
}*/