// Fill out your copyright notice in the Description page of Project Settings.

#include "CommonAncestor.h"
#define maxi(a,b) ((a)<(b)?(b):(a))

// Sets default values
ACommonAncestor::ACommonAncestor()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//preset stats
	bleed.AddZeroed(400);
	BleedNum = 0;
	BleedTime = 0.0f;
	InvulTime = 0.0f;
	Health = 100;
	MaxHealth = 100;
	Mana = 100;
	MaxMana = 100;
}

// Called when the game starts or when spawned
void ACommonAncestor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACommonAncestor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	BleedTime += DeltaTime;
	if (BleedTime >= 0.25f)
	{
		BleedDamage(bleed[BleedNum]);
		bleed[BleedNum] = 0;
		BleedTime -= 0.25f;
		BleedNum += 1;
		if (BleedNum == 400) BleedNum = 0;
	}
	InvulTime = maxi(0.0f, InvulTime - DeltaTime);

}

// Called to bind functionality to input
void ACommonAncestor::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACommonAncestor::BleedDamage(int32 Damage)
{
	if (InvulTime <= 0.01f)
	{
		Health -= Damage;
		if (Health <= 0) Dead();
	}
	
}
void ACommonAncestor::Dead()
{
	Destroy();
}
void ACommonAncestor::Ataka(ACommonAncestor victim,float AtakaTime)
{
	if(AtakaTime>=1)
}