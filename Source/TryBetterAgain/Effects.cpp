// Fill out your copyright notice in the Description page of Project Settings.

#include "Effects.h"

UEffects::UEffects()
{
	IsPermanent = false;
	EffectTime = 0.0f;
	IsPositive = true;
	Dispellable = false;
}

UEffects::~UEffects()
{
}
void UEffects::DeleteSelf()
{
}
void UEffects::Apply(float Delta)
{
	if (!IsPermanent) EffectTime -= Delta;
}
