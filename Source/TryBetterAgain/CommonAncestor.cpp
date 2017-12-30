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
	//*
	Victim->Health -= (AttackDamage*(int)(100*Victim->PhysicMultiplier))/100;
	Victim->UpdateHealthBar();//may be deleted
	if (Victim->Health <= 0) Victim->Dead();
	//*/
	
}
void ACommonAncestor::UpdateAll()
{
//*
	MaxMana = (MaxManaA*(int)(MaxManaM * 100)) / 100;
	if (Mana <= 0) Mana=0;
	if (Mana > MaxMana) Mana = MaxMana;

	AttackDamage = (AttackDamageA*(int)(AttackDamageM * 100)) / 100;
	AttackSpeed = (AttackSpeedA*(int)(AttackSpeedM * 100)) / 100;
	AttackTime = 150.0f / AttackSpeed;
	PunchRate = (AttackSpeed*PunchTime) / (150.0f);
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
	//UpdateHealthBar();*/
}





void ACommonAncestor::UpdateExp()
{
	//*
	if (Exp > LvlExp)
	{
		lvl++;
		Exp -= LvlExp;
		LvlExp *= 1.4;
		AttackDamageM /= 0.95f;
		AttackSpeedM *= 0.95f;
		UpdateAll();
		UpdateHealthBar();
	}
	//*/
}
void ACommonAncestor::InitStats()
{
	//*
	TimeToUpdate = 0.0f;

	Health = 100;
	BaseMaxHealthA = 100;
	BaseMaxHealthM = 1.0f;
	Mana = 100;
	BaseMaxManaA = 100;
	BaseMaxManaM = 1.0f;

	BaseAttackRangeA = 100;
	BaseAttackRangeM = 1.0f;
	BaseAttackDamageA = 10;
	BaseAttackDamageM = 1.0f;
	BaseAttackSpeedA = 100;
	BaseAttackSpeedM = 1.0f;
	PreAttack = 0.45f;
	ISRange = false;
	BaseAttackRangeA = 500;
	BaseAttackRangeM = 1.0f;
	BaseMeleeAttackRangeA = 150;

	BaseMagicPowerA = 0;
	BaseMagicPowerM = 1.0f;
	BaseMagicRangeA = 0;
	BaseMagicRangeM = 1.0f;
	BaseCastTimeA = 0;
	BaseCastTimeM = 1.0f;
	BaseCoolDownTimeA = 0;
	BaseCoolDownTimeM = 1.0f;

	BaseArmorA = 0;
	BaseArmorM = 1.0f;
	BaseNegateArmorA = 0;
	BaseNegateArmorM = 1.0f;
	BasePhysicMultiplierM = 1.0f;
	BaseMagicMultiplierM = 1.0f;
	BaseRedStA = 0;
	BaseRedStM = 1.0f;
	BaseGreenStA = 0;
	BaseGreenStM = 1.0f;
	BaseBlueStA = 0;
	BaseBlueStM = 1.0f;
	Exp = 0;
	lvl = 1;
	LvlExp = 100;
	//extra
	FireStacks = 0;
	ElectricStacks = 0.0f;
	ResetStats();
	UpdateAll();
	//*/
}
void ACommonAncestor::ResetStats()
{
	//*
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
			if (LastPermanent->IsVisual) LastPermanent = NewEff;
			if (LastPositive->IsVisual) LastPositive = NewEff;
		}
		else
		{
			if (Permanent)
			{
				NewEff->next = LastPermanent->next;
				NewEff->prev = LastPermanent->prev;
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
		iter->EffectTime -= Delta;
		UE_LOG(LogTemp, Warning, TEXT("EffectTime=%f"), iter->EffectTime);
		iter = iter->prev;
		if (iter->next->EffectTime < 0.0f)
		{
			DeleteEffect(iter->next);
		}
		else CalcOneEffect(iter->next,Delta);
		
	}
	while (!iter->IsVisual)
	{
		CalcOneEffect(iter,Delta);
		iter = iter->prev;
	}
	//*/
}
void ACommonAncestor::CalcOneEffect(Effects* iter,float Delta)
{
	//*
	while(Delta>0.25f) {
		Delta -= 0.25f;
		UE_LOG(LogTemp, Warning, TEXT("IsSingle problems"));
		if (!iter->IsSingle)
		{
			UE_LOG(LogTemp, Warning, TEXT("Absolutely shure updating"));
			//health&&mana
			TickHealthA += iter->TickHealthA;
			TickHealthM *= iter->TickHealthM;
			TickMHealthA += iter->TickMHealthA;
			TickPHealthA += iter->TickPHealthA;
			iter->MaxHealthA += iter->TickMaxHealthA;
			iter->MaxHealthM *= iter->TickMaxHealthM;
			iter->MaxManaA += iter->TickMaxManaA;
			iter->MaxManaM *= iter->TickMaxManaM;
			//attack
			iter->AttackDamageA += iter->TickAttackDamageA;
			iter->AttackDamageM *= iter->TickAttackDamageM;
			iter->AttackSpeedA += iter->TickAttackSpeedA;
			iter->AttackSpeedM *= iter->TickAttackSpeedM;
			iter->PreAttack += iter->TickPreAttack;
			iter->AttackRangeA += iter->TickAttackRangeA;
			iter->MeleeAttackRangeA += iter->TickMeleeAttackRangeA;
			iter->AttackRangeM *= iter->TickAttackRangeM;
			//magic
			iter->MagicPowerA += iter->TickMagicPowerA;
			iter->MagicPowerM *= iter->TickMagicPowerM;
			iter->MagicRangeA += iter->TickMagicRangeA;
			iter->MagicRangeM *= iter->TickMagicRangeM;
			iter->CastTimeA += iter->TickCastTimeA;
			iter->CastTimeM *= iter->TickCastTimeM;
			iter->CoolDownTimeA += iter->TickCoolDownTimeA;
			iter->CoolDownTimeM *= iter->TickCoolDownTimeM;
			//armor&&resist
			iter->ArmorA += iter->TickArmorA;
			iter->ArmorM *= iter->TickArmorM;
			iter->NegateArmorA += iter->TickNegateArmorA;
			iter->NegateArmorM *= iter->TickNegateArmorM;
			iter->PhysicMultiplierM *= iter->TickPhysicMultiplierM;
			iter->MagicMultiplierM *= iter->TickMagicMultiplierM;
			//base stats
			iter->RedStA += iter->TickRedStA;
			iter->RedStM *= iter->TickRedStM;
			iter->GreenStA += iter->TickGreenStA;
			iter->GreenStM *= iter->TickGreenStM;
			iter->BlueStA += iter->TickBlueStA;
			iter->BlueStM *= iter->TickBlueStM;
		}
	}
	UE_LOG(LogTemp, Warning, TEXT("problems?"));
	MaxHealthA += iter->MaxHealthA;
	MaxHealthM *= iter->MaxHealthM;
	MaxManaA += iter->MaxManaA;
	MaxManaM *= iter->MaxManaM;

	AttackDamageA += iter->AttackDamageA;
	AttackDamageM *= iter->AttackDamageM;
	AttackSpeedA += iter->AttackSpeedA;
	AttackSpeedM *= iter->AttackSpeedM;
	AttackRangeA += iter->AttackRangeA;
	MeleeAttackRangeA += iter->MeleeAttackRangeA;
	AttackRangeM *= iter->AttackRangeM;

	MagicPowerA += iter->MagicPowerA;
	MagicPowerM *= iter->MagicPowerM;
	MagicRangeA += iter->MagicRangeA;
	MagicRangeM *= iter->MagicRangeM;
	CastTimeA += iter->CastTimeA;
	CastTimeM *= iter->CastTimeM;
	CoolDownTimeA += iter->CoolDownTimeA;
	CoolDownTimeM *= iter->CoolDownTimeM;

	ArmorA += iter->ArmorA;
	ArmorM *= iter->ArmorM;
	NegateArmorA += iter->NegateArmorA;
	NegateArmorM *= iter->NegateArmorM;
	PhysicMultiplierM *= iter->PhysicMultiplierM;
	MagicMultiplierM *= iter->MagicMultiplierM;

	RedStA += iter->RedStA;
	RedStM *= iter->RedStM;
	GreenStA += iter->GreenStA;
	GreenStM *= iter->GreenStM;
	BlueStA += iter->BlueStA;
	BlueStM *= iter->BlueStM;
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