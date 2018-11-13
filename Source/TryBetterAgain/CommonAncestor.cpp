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
	//preset stats

	InitStats();
	//*/
}

ACommonAncestor::~ACommonAncestor()
{
	/*
	UEffects* iter;
	iter = BaseInfluence->next;
	while (iter != BaseInfluence)
	{
		iter = iter->next;
		DeleteEffect(iter->prev);
	}
	DeleteEffect(BaseInfluence);
	BaseInfluence = nullptr;

	iter = BasePermanent->next;
	while (iter != BasePermanent)
	{
		iter = iter->next;
		DeleteEffect(iter->prev);
	}
	DeleteEffect(BasePermanent);
	BasePermanent = nullptr;

	iter = BaseTemporal->next;
	while (iter != BaseTemporal)
	{
		iter = iter->next;
		DeleteEffect(iter->prev);
	}
	DeleteEffect(BaseTemporal);
	BaseTemporal = nullptr;
	*/
}

// Called when the game starts or when spawned
void ACommonAncestor::BeginPlay()
{
	InitStats();
	Super::BeginPlay();

	BaseInfluence = NewObject<UEffects>();
	BaseInfluence->next = BaseInfluence;
	BaseInfluence->prev = BaseInfluence;
	BaseTemporal = NewObject <UEffects>();
	BaseTemporal->next = BaseTemporal;
	BaseTemporal->prev = BaseTemporal;
	BasePermanent = NewObject<UEffects>();
	BasePermanent->next = BasePermanent;
	BasePermanent->prev = BasePermanent;
	if (BaseInfluence == nullptr || BaseTemporal == nullptr || BasePermanent == nullptr) Destroy();
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
	EffectiveCD = DeltaTime / RealM["CoolDownTime"];
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
		UpdateAll();
		UpdateHealthBar();
	}
	
}

void ACommonAncestor::Dead()
{
	//GetController()->Destroy();
	UEffects* iter;
	iter = BaseInfluence->next;
	while (iter != BaseInfluence)
	{
		iter = iter->next;
		DeleteEffect(iter->prev);
	}
	DeleteEffect(BaseInfluence);
	BaseInfluence = nullptr;

	iter = BasePermanent->next;
	while (iter != BasePermanent)
	{
		iter = iter->next;
		DeleteEffect(iter->prev);
	}
	DeleteEffect(BasePermanent);
	BasePermanent = nullptr;

	iter = BaseTemporal->next;
	while (iter != BaseTemporal)
	{
		iter = iter->next;
		DeleteEffect(iter->prev);
	}
	DeleteEffect(BaseTemporal);
	BaseTemporal = nullptr;
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

	Health += RealA["HealthRegen"] * RealM["HealthRegen"];
	Health -= RealA["TickDamage"] * RealM["TickDamage"];
	if (Health <= 0) Dead();
	MaxHealth = RealA["MaxHealth"] * RealM["MaxHealth"];
	if (Health > MaxHealth) Health = MaxHealth;

	Mana += RealA["ManaRegen"] * RealM["ManaRegen"];
	Mana -= RealA["ManaDiffuse"] * RealM["ManaDiffuse"];
	MaxMana = RealA["MaxMana"] * RealM["MaxMana"];
	if (Mana <= 0) Mana=0;
	if (Mana > MaxMana) Mana = MaxMana;

	AttackDamage=RealA["AttackDamage"] * RealM["AttackDamage"];
	AttackSpeed = RealA["AttackSpeed"] * RealM["AttackSpeed"];
	AttackTime = 150.0f / AttackSpeed;
	PunchRate = (AttackSpeed*PunchTime) / (150.0f);
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
	BaseA.Add("HealthRegen", 0);//восстановление хп за тик
	BaseM.Add("HealthRegen", 1.);//множитель восстановления здоровья
	BaseA.Add("TickDamage", 0);//дот эффекты
	BaseM.Add("TickDamage", 1.);
	BaseA.Add("MaxHealth", 100);
	BaseM.Add("MaxHealth", 1.);
	//EverlastingA.Add("Mana", 100);
	Mana = 100;
	BaseA.Add("ManaRegen", 0);//восстановление маны за тик
	BaseM.Add("ManaRegen", 1.);//множитель восстановления маны
	BaseA.Add("ManaDiffuse", 0);//сжигание маны
	BaseM.Add("ManaDiffuse", 1.);//сжигание маны
	BaseA.Add("MaxMana", 100);
	BaseM.Add("MaxMana", 1.);

	/*BaseMaxHealthA = 100;
	BaseMaxHealthM = 1.0f;
	BaseMaxManaA = 100;
	BaseMaxManaM = 1.0f;
	*/
	BaseA.Add("MaxAttackRange", 500);
	BaseM.Add("MaxAttackRange", 1.);
	BaseA.Add("AttackDamage", 100);
	BaseM.Add("AttackDamage", 1.);
	BaseA.Add("AttackSpeed", 100);
	BaseM.Add("AttackSpeed", 1.);
	PreAttack = 0.45f;
	ISRange = false;
	BaseA.Add("MeleeAttackRange", 150);

	/*
	BaseAttackDamageA = 10;
	BaseAttackDamageM = 1.0f;
	BaseAttackSpeedA = 100;
	BaseAttackSpeedM = 1.0f;
	BaseAttackRangeA = 500;
	BaseAttackRangeM = 1.0f;
	BaseMeleeAttackRangeA = 150;
	*/
	BaseA.Add("MagicPower", 0);
	BaseM.Add("MagicPower", 1.);
	BaseA.Add("MagicRange", 0);
	BaseM.Add("MagicRange", 1.);
	BaseA.Add("CastTime", 0);
	BaseM.Add("CastTime", 1.);
	BaseA.Add("CoolDownTime", 0);
	BaseM.Add("CoolDownTime", 1.);
/*
	BaseMagicPowerA = 0;
	BaseMagicPowerM = 1.0f;
	BaseMagicRangeA = 0;
	BaseMagicRangeM = 1.0f;
	BaseCastTimeA = 0;
	BaseCastTimeM = 1.0f;
	BaseCoolDownTimeA = 0;
	BaseCoolDownTimeM = 1.0f;
	*/
	BaseA.Add("Armor", 100);
	BaseM.Add("Armor", 1.);
	BaseA.Add("NegateArmor", 0);
	BaseM.Add("NegateArmor", 1.);
	BaseM.Add("PhysicMultiplier", 1.);
	BaseM.Add("MagicMultiplier", 1.);
	/*
	BaseArmorA = 0;
	BaseArmorM = 1.0f;
	BaseNegateArmorA = 0;
	BaseNegateArmorM = 1.0f;
	BasePhysicMultiplierM = 1.0f;
	BaseMagicMultiplierM = 1.0f;
	*/
	BaseA.Add("RedSt", 100);
	BaseM.Add("RedSt", 1.);
	BaseA.Add("GreenSt", 100);
	BaseM.Add("GreenSt", 1.);
	BaseA.Add("BlueSt", 100);
	BaseM.Add("BlueSt", 1.);
	
/*
	BaseRedStA = 0;
	BaseRedStM = 1.0f;
	BaseGreenStA = 0;
	BaseGreenStM = 1.0f;
	BaseBlueStA = 0;
	BaseBlueStM = 1.0f;
	*/
	Exp = 0;
	lvl = 1;
	LvlExp = 100;
	ResetStats();
	UpdateAll();
	
}
void ACommonAncestor::ResetStats()
{
	RealA = BaseA;
	RealM = BaseM;
	
}
void ACommonAncestor::AddNewEffect(bool Influent, UEffects* iter )
{
	if (Influent)
	{
		if (iter->IsPositive)
		{
			iter->next = BaseInfluence->next;
			iter->prev = BaseInfluence;
			BaseInfluence->next->prev = iter;
			BaseInfluence->next = iter;
		}
		else
		{
			iter->next = BaseInfluence;
			iter->prev = BaseInfluence->prev;
			BaseInfluence->prev->next = iter;
			BaseInfluence->prev = iter;
		}
	}
	else
	{
		if (iter->IsPermanent)
		{
			if (iter->IsPositive)
			{
				iter->next = BasePermanent->next;
				iter->prev = BasePermanent;
				BasePermanent->next->prev = iter;
				BasePermanent->next = iter;
			}
			else
			{
				iter->next = BasePermanent;
				iter->prev = BasePermanent->prev;
				BasePermanent->prev->next = iter;
				BasePermanent->prev = iter;
			}
		}
		else
		{
			if (iter->IsPositive)
			{
				iter->next = BaseTemporal->next;
				iter->prev = BaseTemporal;
				BaseTemporal->next->prev = iter;
				BaseTemporal->next = iter;
			}
			else
			{
				iter->next = BaseTemporal;
				iter->prev = BaseTemporal->prev;
				BaseTemporal->prev->next = iter;
				BaseTemporal->prev = iter;
			}
		}
	}
	/*
	UEffects* NewEff;
	NewEff = new UEffects;
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
	return NewEff;*/
	//return nullptr;
}
void ACommonAncestor::CalcEffects(float Delta)
{
	//*
	UEffects *iter=BaseInfluence->next;
	while (iter != BaseInfluence)
	{
		iter->Apply(Delta);
		//UE_LOG(LogTemp, Warning, TEXT("EffectTime=%f"), iter->EffectTime);
		iter = iter->next;
		if (iter->prev->EffectTime < 0.0f)
		{
			DeleteEffect(iter->prev);
		}
	}
	iter = BasePermanent->next;
	while (iter != BasePermanent)
	{
		iter->Apply(Delta);
		iter = iter->next;
	}
	iter = BaseTemporal->next;
	while (iter != BaseTemporal)
	{
		iter->Apply(Delta);
	//	UE_LOG(LogTemp, Warning, TEXT("EffectTime=%f"), iter->EffectTime);
		iter = iter->next;
		if (iter->prev->EffectTime < 0.0f)
		{
			DeleteEffect(iter->prev);
		}
	}
	/*while (!iter->IsPermanent)
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


void ACommonAncestor::DeleteEffect(UEffects* iter)
{
	iter->DeleteSelf();
	iter->prev->next = iter->next;
	iter->next->prev = iter->prev;
	iter->next = nullptr;
	iter->prev = nullptr;
	/*
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
UEffects* ACommonAncestor::FindName(ENameEffects Number, bool OnlyInfluence)
{
	if (BaseInfluence == nullptr || BaseTemporal == nullptr || BasePermanent == nullptr) return nullptr;
	UEffects* iter;
	iter=BaseInfluence->next;
	while (iter != BaseInfluence)
	{
		if (iter->Name == Number) return iter;
		iter = iter->next;
	}
	if (!OnlyInfluence)
	{
		iter = BasePermanent->next;
		while (iter != BasePermanent)
		{
			if (iter->Name == Number) return iter;
			iter = iter->next;
		}
		iter = BaseTemporal->next;
		while (iter != BaseTemporal)
		{
			if (iter->Name == Number) return iter;
			iter = iter->next;
		}
	}
	/*
	UEffects* iter;
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
		break;
	case DamageType::Magic:
		Victim->Health -= Damage* Victim->RealM["MagicMultiplier"];
		Victim->UpdateHealthBar();//may be deleted
		if (Victim->Health <= 0) Victim->Dead();
	}
}