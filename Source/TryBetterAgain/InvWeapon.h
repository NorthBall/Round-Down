// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InvWeapon.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class TRYBETTERAGAIN_API UInvWeapon:public UObject
{
	GENERATED_BODY()
public:
	UInvWeapon();
	
	//stats
		//attack
	int32 AttackDamageA;
	float PhysM;
	int32 AttackRangeA;
	float AttackRangeM;
	int32 AttackSpeedA;
	float AttackSpeedM;
		//physics
	int32 ArmorA;
	float ArmorM;
		//magic
	int32 MagicPowerA;
	float MagicPowerM;
	int32 MagicRangeA;
	float MagicRangeM;
	int32 CDA;
	float CDM;
	int32 CastTimeA;
	float CastTimeM;
		//health
	int32 HPA;
	float HPM;
	int32 MPA;
	float MPM;


};
