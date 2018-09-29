// Fill out your copyright notice in the Description page of Project Settings.

#include "CommonAncestor.h"
#include "InvWeapon.h"
#include "Effects.h"
#define maxweapons 20
#define maxi(a,b) ((a)<(b)?(b):(a))
#define maxskills 30
#define mini(a,b) ((a)<(b)?(a):(b))

// Sets default values
ACommonAncestor::ACommonAncestor()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//set arrays
//*
	WeapType.AddZeroed(maxweapons);
	HaveWeap.AddZeroed(maxweapons);
	WeapSlots.AddZeroed(maxweapons);
	SkillCDTimes.AddZeroed(maxskills);
	SkillLevel.AddZeroed(maxskills);
	Base = new Effects;
	Base->next = Base;
	Base->prev = Base;
	Base->IsPermanent = true;
	Base->IsVisual = true;
	LastPositive = Base;
	LastPermanent = Base;
	//preset stats

	InitStats();
	InvulTime = 0.0f;
	//*/
}

// Called when the game starts or when spawned
void ACommonAncestor::BeginPlay()
{
	Super::BeginPlay();
	if (Base == nullptr || LastPermanent == nullptr || LastPositive == nullptr) Destroy();
	//if (HaveWeap[0]==false) UE_LOG(LogTemp, Warning, TEXT("NotHavingWeap"));

	//InitStats();
	InvulTime = 0.0f;
}

// Called every frame
void ACommonAncestor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TickExample(DeltaTime);
	//*InvulTime = maxi(0.0f, InvulTime - DeltaTime);
	//*/
}
void ACommonAncestor::TickExample(float DeltaTime)
{
	EffectiveCD = DeltaTime / CoolDownTimeM;
	for (i = 0; i < maxskills; i++)
	{
		SkillCDTimes[i] = maxi(0, SkillCDTimes[i] - EffectiveCD);
	}
	TimeToUpdate += DeltaTime;
	if (TimeToUpdate > 0.25f)
	{
		ResetStats();
		CalcEffects(TimeToUpdate);
		TimeToUpdate -= 0.25f;
		//UE_LOG(LogTemp, Warning, TEXT("TimeToUpdatebug=%f"), TimeToUpdate);
		UpdateAll();
		UpdateHealthBar();
	}
	
}

void ACommonAncestor::Dead()
{
	//GetController()->Destroy();
	Destroy();
}
void ACommonAncestor::DoAttack(ACommonAncestor *Victim)
{
	//
	Victim->Health -= AttackDamage*Victim->PhysicMultiplier;
	Victim->UpdateHealthBar();//may be deleted
	if (Victim->Health <= 0) Victim->Dead();
	//*/
	
}
void ACommonAncestor::UpdateAll()
{

	//Health += RealA["TickHealth"] * RealM["HealHealth"];
	//
	//if (Health <= 0) Dead();
	//if (Health > MaxHealth) Health = MaxHealth;
	//Mana += RealA["TickMana"] * RealM["HealMana"];

	//if (Mana <= 0) Mana = 0;
	//if (Mana > MaxMana) Mana = MaxMana;
	MaxMana = (MaxManaA*(int)(MaxManaM * 100)) / 100;
	if (Mana <= 0) Mana=0;
	if (Mana > MaxMana) Mana = MaxMana;

	AttackDamage=RealA["AttackDamage"] * RealM["AttackDamage"];
	AttackSpeed = RealA["AttackSpeed"] * RealM["AttackSpeed"];
	AttackTime = 150.0f / AttackSpeed;
	PunchRate = (AttackSpeed*PunchTime) / (150.0f);
	//if (!HaveWeap[0]) PunchRate *= 1.2f;
	DamagePerSecond = AttackDamage * (AttackSpeed / 150.f);
	if (ISRange)
		AttackRange = RealA["AttackRange"] * RealM["AttackRange"];
	else
		AttackRange = RealA["MeleeAttackRange"];
	RedSt = RealA["RedSt"] * RealM["RedSt"];
	GreenSt = RealA["GreenSt"] * RealM["GreenSt"];
	BlueSt = RealA["BlueSt"] * RealM["BlueSt"];
	Armor = RealA["Armor"] * RealM["Armor"]-RealA["NegateArmor"]*RealM["NegateArmor"];
	if (Armor>0.0f)
		PhysicMultiplier = (100.0f) / (100 + Armor)*RealM["PhysicMultiplier"];
	else
		PhysicMultiplier = ((100 - Armor) / 100.0f) * RealM["PhysicMultiplier"];

	AttackDamage = (AttackDamageA*(int)(AttackDamageM * 100)) / 100;
	AttackSpeed = (AttackSpeedA*(int)(AttackSpeedM * 100)) / 100;
	AttackTime = 150.0f / AttackSpeed;
	PunchRate = (AttackSpeed*PunchTime) / (150.0f);
	if (!HaveWeap[0]) PunchRate*=1.2f;
	DamagePerSecond = AttackDamage*(AttackSpeed / 150.f);
	if (ISRange)
		AttackRange = (AttackRangeA*(int)(AttackRangeM * 100)) / 100;
	else
		AttackRange = MeleeAttackRangeA;
	RedSt = (RedStA*(int)(RedStM * 100)) / 100;
	GreenSt = (GreenStA*(int)(GreenStM * 100)) / 100;
	BlueSt = (BlueStA*(int)(BlueStM * 100)) / 100;
	Armor = (ArmorA*(int)(ArmorM * 100)) / 100 - (NegateArmorA*(int)(NegateArmorM * 100)) / 100;
	if (Armor > 0.0f)
	{
		PhysicMultiplier = (100.0f) / (100 + Armor)*PhysicMultiplierM;
	}
	else
	{
		PhysicMultiplier = ((100 - Armor) / 100.0f) * PhysicMultiplierM;
	}
	Health += TickHealthA;
	Health += TickPHealthA*PhysicMultiplier;
	Health += TickMHealthA*MagicMultiplierM;
	Health *= TickHealthM;
	MaxHealth = (MaxHealthA*(int)(MaxHealthM * 100)) / 100;
	if (Health <= 0) Dead();
	if (Health > MaxHealth) Health = MaxHealth;
	//UpdateHealthBar();
}





void ACommonAncestor::UpdateExp()
{
	//*
	if (Exp > LvlExp)
	{
		lvl++;
		Exp -= LvlExp;
		LvlExp *= 1.4;
		BaseM["AttackDamage"] /= 0.95f;
		BaseM["AttackSpeed"] *= 0.95f;
		UpdateAll();
		UpdateHealthBar();
	}
	//*/
}
void ACommonAncestor::InitStats()
{
	//*
	TimeToUpdate = 0.0f;

	//EverlastingA.Add("Health", 100);
	Health = 100;
	BaseA.Add("TickHealth", 0);//восстановление хп за тик
	BaseM.Add("HealHealth", 1.);//множитель восстановления здоровья
	BaseA.Add("MaxHealth", 100);
	BaseM.Add("MaxHealth", 1.);
	//EverlastingA.Add("Mana", 100);
	Mana = 100;
	BaseA.Add("TickMana", 0);//восстановление маны за тик
	BaseM.Add("HealMana", 1.);//множитель восстановления маны
	BaseA.Add("MaxMana", 100);
	BaseM.Add("MaxMana", 1.);

	BaseMaxHealthA = 100;
	BaseMaxHealthM = 1.0f;
	BaseMaxManaA = 100;
	BaseMaxManaM = 1.0f;

	BaseA.Add("MaxAttackRange", 500);
	BaseM.Add("MaxAttackRange", 1.);
	BaseA.Add("AttackDamage", 100);
	BaseM.Add("AttackDamage", 1.);
	BaseA.Add("AttackSpeed", 100);
	BaseM.Add("AttackSpeed", 1.);
	PreAttack = 0.45f;
	ISRange = false;
	BaseA.Add("MeleeAttackRange", 150);


	BaseAttackDamageA = 10;
	BaseAttackDamageM = 1.0f;
	BaseAttackSpeedA = 100;
	BaseAttackSpeedM = 1.0f;
	BaseAttackRangeA = 500;
	BaseAttackRangeM = 1.0f;
	BaseMeleeAttackRangeA = 150;

	BaseA.Add("MagicPower", 0);
	BaseM.Add("MagicPower", 1.);
	BaseA.Add("MagicRange", 0);
	BaseM.Add("MagicRange", 1.);
	BaseA.Add("CastTime", 0);
	BaseM.Add("CastTime", 1.);
	BaseA.Add("CoolDownTime", 0);
	BaseM.Add("CoolDownTime", 1.);

	BaseMagicPowerA = 0;
	BaseMagicPowerM = 1.0f;
	BaseMagicRangeA = 0;
	BaseMagicRangeM = 1.0f;
	BaseCastTimeA = 0;
	BaseCastTimeM = 1.0f;
	BaseCoolDownTimeA = 0;
	BaseCoolDownTimeM = 1.0f;

	BaseA.Add("Armor", 100);
	BaseM.Add("Armor", 1.);
	BaseA.Add("NegateArmor", 0);
	BaseM.Add("NegateArmor", 1.);
	BaseM.Add("PhysicMultiplier", 1.);
	BaseM.Add("MagicMultiplier", 1.);

	BaseArmorA = 0;
	BaseArmorM = 1.0f;
	BaseNegateArmorA = 0;
	BaseNegateArmorM = 1.0f;
	BasePhysicMultiplierM = 1.0f;
	BaseMagicMultiplierM = 1.0f;

	BaseA.Add("RedSt", 100);
	BaseM.Add("RedSt", 1.);
	BaseA.Add("GreenSt", 100);
	BaseM.Add("GreenSt", 1.);
	BaseA.Add("BlueSt", 100);
	BaseM.Add("BlueSt", 1.);
	

	BaseRedStA = 0;
	BaseRedStM = 1.0f;
	BaseGreenStA = 0;
	BaseGreenStM = 1.0f;
	BaseBlueStA = 0;
	BaseBlueStM = 1.0f;

	Exp = 0;
	lvl = 1;
	LvlExp = 100;
	ResetStats();
	UpdateAll();
	
}
void ACommonAncestor::ResetStats()
{
	//*
	RealA = BaseA;
	RealM = BaseM;

	TickHealthA = 0;
	TickPHealthA = 0;
	TickMHealthA = 0;
	TickHealthM = 1.0f;
	MaxHealthA = BaseMaxHealthA;
	MaxHealthM = BaseMaxHealthM;
	MaxManaA = BaseMaxManaA;
	MaxManaM = BaseMaxManaM;

	AttackDamageA = BaseAttackDamageA;
	AttackDamageM = BaseAttackDamageM;
	AttackSpeedA = BaseAttackSpeedA;
	AttackSpeedM = BaseAttackSpeedM;
	AttackRangeA = BaseAttackRangeA;
	MeleeAttackRangeA = BaseMeleeAttackRangeA;
	AttackRangeM = BaseAttackRangeM;

	MagicPowerA = BaseMagicPowerA;
	MagicPowerM = BaseMagicPowerM;
	MagicRangeA = BaseMagicRangeA;
	MagicRangeM = BaseMagicRangeM;
	CastTimeA = BaseCastTimeA;
	CastTimeM = BaseCastTimeM;
	CoolDownTimeA = BaseCoolDownTimeA;
	CoolDownTimeM = BaseCoolDownTimeM;

	ArmorA = BaseArmorA;
	ArmorM = BaseArmorM;
	NegateArmorA = BaseNegateArmorA;
	NegateArmorM = BaseNegateArmorM;
	PhysicMultiplierM = BasePhysicMultiplierM;
	MagicMultiplierM = BaseMagicMultiplierM;

	RedStA = BaseRedStA;
	RedStM = BaseRedStM;
	GreenStA = BaseGreenStA;
	GreenStM = BaseGreenStM;
	BlueStA = BaseBlueStA;
	BlueStM = BaseBlueStM;//*/
}
Effects* ACommonAncestor::AddNewEffect(bool Visual,bool Permanent, bool Positive ,NameEffects Number, float Time )
{
	//*
	Effects* NewEff;
	NewEff = new Effects;
	if (NewEff != nullptr)
	{
		NewEff->IsVisual = Visual;
		NewEff->IsPermanent = Permanent;
		NewEff->IsPositive = Positive;
		NewEff->EffectTime = Time;
		NewEff->Name = Number;
		if (Visual)  { 
			NewEff->next = Base->next;
			NewEff->prev = Base;
			Base->next->prev = NewEff;
			Base->next = NewEff;
			if (LastPermanent==Base) LastPermanent = NewEff;
			if (LastPositive==Base) LastPositive = NewEff;
		}
		else
		{
			if (Permanent)
			{
				NewEff->next = LastPermanent->next;
				NewEff->prev = LastPermanent;
				LastPermanent->next->prev = NewEff;
				LastPermanent->next = NewEff;
				LastPermanent = NewEff;
				if (LastPositive->IsPermanent) LastPositive = NewEff;
			}
			else
			{
				if (Positive)
				{
					NewEff->next = LastPositive->next;
					NewEff->prev = LastPositive;
					LastPositive->next->prev = NewEff;
					LastPositive->next = NewEff;
					LastPositive = NewEff;
				}
				else
				{
					NewEff->next = Base;
					NewEff->prev = Base->prev;
					Base->prev->next = NewEff;
					Base->prev = NewEff;
				}
			}
		}
	}
	else return nullptr;
	return NewEff;//*/
	//return nullptr;
}
void ACommonAncestor::CalcEffects(float Delta)
{
	//*
	Effects *iter=(Base->prev);
	while (!iter->IsPermanent)
	{
		iter->Apply(Delta);
		UE_LOG(LogTemp, Warning, TEXT("EffectTime=%f"), iter->EffectTime);
		iter = iter->prev;
		if (iter->next->EffectTime < 0.0f)
		{
			DeleteEffect(iter->next);
		}
		
	}
	while (!iter->IsVisual)
	{
		iter->Apply(Delta);
		iter = iter->prev;
	}
	//*/
}


void ACommonAncestor::DeleteEffect(Effects* iter)
{
	//*
	iter->prev->next = iter->next;
	iter->next->prev = iter->prev;
	if (iter == LastPermanent)
	{
		LastPermanent = iter->prev;
	}
	if (iter == LastPositive)
	{
		LastPositive = iter->prev;
	}
	delete iter;
	//*/
}
Effects* ACommonAncestor::FindName(NameEffects Number)
{
	//*
	Effects* iter;
	iter = Base->prev;
	while (iter != Base)
	{
		if (iter->Name == Number) return iter;
		iter = iter->prev;
	}//*/
	return nullptr;
}
void  ACommonAncestor::DealDamage(ACommonAncestor *Victim, int Damage, DamageType Type)
{
	switch (Type) {
	case DamageType::Pure :
		Victim->Health -= Damage;
		Victim->UpdateHealthBar();//may be deleted
		if (Victim->Health <= 0) Victim->Dead();
		break;
	case DamageType::Physical :
		Victim->Health -= Damage*Victim->PhysicMultiplier;
		Victim->UpdateHealthBar();//may be deleted
		if (Victim->Health <= 0) Victim->Dead();
	case DamageType::Magic:
		Victim->Health -= Damage* Victim->MagicMultiplierM;
		Victim->UpdateHealthBar();//may be deleted
		if (Victim->Health <= 0) Victim->Dead();
	}
}