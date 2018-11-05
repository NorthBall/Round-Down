// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Effects.generated.h"

UCLASS(Blueprintable)
/**
 * 
 */
class TRYBETTERAGAIN_API UEffects: public UObject
{
	GENERATED_BODY()
public:
	UEffects();
	virtual ~UEffects();
	virtual void DeleteSelf();//if need delete something faster? than GC will do
	UPROPERTY()
	UEffects *prev;
	UPROPERTY()
	UEffects *next;
	//class ACommonAncestor *owner;
	bool IsPermanent;//permanent Effects will not update
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