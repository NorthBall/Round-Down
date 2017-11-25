// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class TRYBETTERAGAIN_API TableSkil
{
public:
	TableSkil();
	~TableSkil();
	TArray<int32> Cell;
	TArray<TArray <int32>> Line;
	TArray <TArray <TArray <int32>>> Table;
};
enum class Skill {
	FireBLink
};
