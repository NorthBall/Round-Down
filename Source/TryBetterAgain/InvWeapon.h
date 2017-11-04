// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class TRYBETTERAGAIN_API InvWeapon
{
public:
	InvWeapon();
	~InvWeapon();
	//stats
		//attack
	int32 AttackDamageA;
	float PhysM;
	int32 AttackDistA;
	float AttackDistM;
	int32 AttackSpeedA;
	float AttackSpeedM;
		//physics
	int32 ArmorA;
	float ArmorM;
		//magic
	int32 MagicPowerA;
	float MagicPowerM;
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
