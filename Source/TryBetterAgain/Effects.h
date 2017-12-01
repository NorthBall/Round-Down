// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <map>
#include <string>

/**
 * 
 */
class TRYBETTERAGAIN_API Effects
{
public:
	Effects();
	~Effects();
	Effects *prev;
	Effects *next;
	//class ACommonAncestor *owner;
	bool IsVisual;//visuals aren't effects, just visual representation
	bool IsPermanent;//permanent effects will not update
	bool IsSingle;//single effects will be updated only after they dissapear
	float EffectTime;
	bool IsPositive;
	enum class NameEffects Name;
	int32 SpecInt;
	float SpecFloat;
	//std::map <std::string,int32> IntByTick;

	//Stats area
	//health and mana
		int32 MaxHealthA;
		float MaxHealthM;
		int32 MaxManaA;
		float MaxManaM;
	//attack
		int32 AttackDamageA;
		float AttackDamageM;
		int32 AttackSpeedA;
		float AttackSpeedM;
		float PreAttack;
		int32 AttackRangeA;
		int32 MeleeAttackRangeA;
		float AttackRangeM;
	//Magic
		int32 MagicPowerA;
		float MagicPowerM;
		int32 MagicRangeA;
		float MagicRangeM;
		int32 CastTimeA;
		float CastTimeM;
		int32 CoolDownTimeA;
		float CoolDownTimeM;
	//Armor&&resist
		int32 ArmorA;
		float ArmorM;
		int32 NegateArmorA;
		float NegateArmorM;
		float PhysicMultiplierM;
		float MagicMultiplierM;
	//base stats
		int32 RedStA;
		int32 GreenStA;
		int32 BlueStA;
		float RedStM;
		float GreenStM;
		float BlueStM;
	//function area
		void NullifyStats();
		//health and mana
		int32 TickHealthA;
		float TickHealthM;
		int32 TickMaxHealthA;
		float TickMaxHealthM;
		int32 TickManaA;
		float TickManaM;
		int32 TickMaxManaA;
		float TickMaxManaM;
		//attack
		int32 TickAttackDamageA;
		float TickAttackDamageM;
		int32 TickAttackSpeedA;
		float TickAttackSpeedM;
		float TickPreAttack;
		int32 TickAttackRangeA;
		int32 TickMeleeAttackRangeA;
		float TickAttackRangeM;
		//Magic
		int32 TickMagicPowerA;
		float TickMagicPowerM;
		int32 TickMagicRangeA;
		float TickMagicRangeM;
		int32 TickCastTimeA;
		float TickCastTimeM;
		int32 TickCoolDownTimeA;
		float TickCoolDownTimeM;
		//Armor&&resist
		int32 TickArmorA;
		float TickArmorM;
		int32 TickNegateArmorA;
		float TickNegateArmorM;
		float TickPhysicMultiplierM;
		float TickMagicMultiplierM;
		//base stats
		int32 TickRedStA;
		int32 TickGreenStA;
		int32 TickBlueStA;
		float TickRedStM;
		float TickGreenStM;
		float TickBlueStM;
};
enum class NameEffects {
	FireBurnE,
	FireFireS,
	FireAfterBurnE,
	FireBlinkE
	
};
enum class Skill {
	Fire_Start,
	FireBurn,
	FireFire,
	FireAfterBurn,
	FireBlink,
	FireLance,
	Skill_Max
};