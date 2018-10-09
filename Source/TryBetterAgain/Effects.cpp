// Fill out your copyright notice in the Description page of Project Settings.

#include "Effects.h"

Effects::Effects()
{
	IsPermanent = false;
	EffectTime = 0.0f;
	IsPositive = true;
	Dispellable = false;
}

Effects::~Effects()
{
}
void Effects::Apply(float Delta)
{
	if (!IsPermanent) EffectTime -= Delta;
}
