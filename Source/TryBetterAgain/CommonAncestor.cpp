// Fill out your copyright notice in the Description page of Project Settings.

#include "CommonAncestor.h"
#include "InvWeapon.h"
#define maxweapons 20
#define maxi(a,b) ((a)<(b)?(b):(a))

// Sets default values
ACommonAncestor::ACommonAncestor()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//preset stats
	InitStats();
	InvulTime = 0.0f;
	
}

// Called when the game starts or when spawned
void ACommonAncestor::BeginPlay()
{
	Super::BeginPlay();
	if (HaveWeap[0]==false) UE_LOG(LogTemp, Warning, TEXT("NotHavingWeap"));
	//UE_LOG(LogTemp, Warning, TEXT("AttackTime=%f"), AttackTime);
	//UE_LOG(LogTemp, Warning, TEXT("PunchRate=%f"), PunchRate);
}

// Called every frame
void ACommonAncestor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	InvulTime = maxi(0.0f, InvulTime - DeltaTime);

}

// Called to bind functionality to input
void ACommonAncestor::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


void ACommonAncestor::Dead()
{
	Destroy();
}
void ACommonAncestor::DoAttack(ACommonAncestor *Victim)
{
	Victim->Health -= (AttackDamage*(int)(100*Victim->PhysicMultiplier))/100;
	Victim->UpdateHealthBar();//may be deleted
	if (Victim->Health <= 0) Victim->Dead();
}
void ACommonAncestor::UpdateAll()
{
	MaxHealth = (MaxHealthA*(int)(MaxHealthM * 100)) / 100;
	MaxMana = (MaxManaA*(int)(MaxManaM * 100)) / 100;

	AttackDamage = (AttackDamageA*(int)(AttackDamageM * 100)) / 100;
	AttackSpeed = (AttackSpeedA*(int)(AttackSpeedM * 100)) / 100;
	AttackTime = 150.0f / AttackSpeed;
	PunchRate = (AttackSpeed*PunchTime) / (150.0f);
	DamagePerSecond = AttackDamage*(AttackSpeed / 150.f);
	if (ISRange)
		AttackRange = (AttackRangeA*(int)(AttackRangeM * 100)) / 100;
	else
		AttackRange = MeleeAttackRangeA;
	Armor = (ArmorA*(int)(ArmorM * 100)) / 100 - (NegateArmorA*(int)(NegateArmorM * 100)) / 100;
	if (Armor > 0.0f)
	{
		PhysicMultiplier = (100.0f) / (100 + Armor)*PhysicMultiplierM;
	}
	else
	{
		PhysicMultiplier = ((100 - Armor) / 100.0f) / PhysicMultiplierM;
	}
	RedSt = (RedStA*(int)(RedStM * 100)) / 100;
	GreenSt = (GreenStA*(int)(GreenStM * 100)) / 100;
	BlueSt = (BlueStA*(int)(BlueStM * 100)) / 100;
}





void ACommonAncestor::UpdateExp()
{
	if (Exp > LvlExp)
	{
		lvl++;
		Exp -= LvlExp;
		LvlExp *= 1.4;
		AttackDamageM /= 0.95f;
		AttackSpeedM *= 0.95f;
		UpdateAll();
	}
}
void ACommonAncestor::InitStats()
{
	WeapType.AddZeroed(maxweapons);
	HaveWeap.AddZeroed(maxweapons);
	WeapSlots.AddZeroed(maxweapons);
	Health = 100;
	MaxHealthA = 100;
	MaxHealthM = 1.0f;
	MaxHealth = (MaxHealthA*(int)(MaxHealthM * 100)) / 100;

	Mana = 100;
	MaxManaA = 100;
	MaxManaM = 1.0f;
	MaxMana = (MaxManaA*(int)(MaxManaM * 100)) / 100;

	AttackDamageA = 10;
	AttackDamageM = 1.0f;
	AttackDamage = (AttackDamageA*(int)(AttackDamageM * 100)) / 100;
	AttackSpeedA = 100;
	AttackSpeedM = 1.0f;
	AttackSpeed = (AttackSpeedA*(int)(AttackSpeedM * 100)) / 100;
	AttackTime = 150.0f / AttackSpeed;
	PunchRate = (AttackSpeed*PunchTime) / (150.0f);
	DamagePerSecond = AttackDamage*(AttackSpeed / 150.f);
	PreAttack = 0.45f;
	ISRange = false;
	AttackRangeA = 500;
	AttackRangeM = 1.0f;
	MeleeAttackRangeA = 150;
	if (ISRange)
		AttackRange = (AttackRangeA*(int)(AttackRangeM * 100)) / 100;
	else
		AttackRange = MeleeAttackRangeA;
	MagicPowerA = 0;
	MagicPowerM = 1.0f;
	MagicRangeA = 0;
	MagicRangeM = 1.0f;
	ArmorA = 0;
	ArmorM = 1.0f;
	NegateArmorA = 0;
	NegateArmorM = 1.0f;
	Armor = (ArmorA*(int)(ArmorM * 100)) / 100 -(NegateArmorA*(int)(NegateArmorM * 100)) / 100;
	PhysicMultiplierM = 1.0f;
	if (Armor > 0.0f)
	{
		PhysicMultiplier = (100.0f) / (100 + Armor)*PhysicMultiplierM;
	}
	else
	{
		PhysicMultiplier = ((100 - Armor) / 100.0f )/ PhysicMultiplierM;
	}
	RedStA = 0;
	RedStM = 1.0f;
	RedSt = (RedStA*(int)(RedStM * 100)) / 100;
	GreenStA = 0;
	GreenStM = 1.0f;
	GreenSt = (GreenStA*(int)(GreenStM * 100)) / 100;
	BlueStA = 0;
	BlueStM = 1.0f;
	BlueSt = (BlueStA*(int)(BlueStM * 100)) / 100;
	Exp = 0;
	lvl = 1;
	LvlExp = 100;
}