// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


/**
 * 
 */
class TRYBETTERAGAIN_API Effects
{
public:
	Effects();
	virtual ~Effects();
	Effects *prev;
	Effects *next;
	//class ACommonAncestor *owner;
	bool IsPermanent;//permanent effects will not update
	float EffectTime;
	bool IsPositive;//support variables
	bool Dispellable;//
	enum class NameEffects Name;
	virtual void Apply(float Delta);
	class ACommonAncestor* Target,*Caster;

};
enum class NameEffects {
	FireBurnE,
	FireFireS,
	FireAfterBurnE,
	FireBlinkE,
	FireAuraS,
	FireAuraE
	
};
enum class Skill {
	None,
	Fire_Start,
	FireBurn,
	FireFire,
	FireAfterBurn,
	FireMeteor,
	FireQueue,
	FireBlink,
	FireRing,
	FireLance,
	FireAura,
	Skill_Max
};
enum class DamageType {
	Pure,
	Physical,
	Magic
};
enum class BotType
{
	EnigmaWarrior=1,
	EnigmaMage
};