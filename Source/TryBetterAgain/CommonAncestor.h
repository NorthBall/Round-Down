// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CommonAncestor.generated.h"


UCLASS()
class TRYBETTERAGAIN_API ACommonAncestor : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACommonAncestor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void TickExample(float DeltaTime);
//*
	//effects
	float InvulTime;
	//Stats area
	//health and mana
	UPROPERTY(BlueprintReadWrite, Category = "Health")
		int32 Health;
	UPROPERTY(BlueprintReadWrite, Category = "Health")
		int32 TickHealthA;
	UPROPERTY(BlueprintReadWrite, Category = "Health")
		int32 TickPHealthA;
	UPROPERTY(BlueprintReadWrite, Category = "Health")
		int32 TickMHealthA;
	UPROPERTY(BlueprintReadWrite, Category = "Health")
		int32 TickHealthM;
	UPROPERTY(BlueprintReadWrite,VisibleAnywhere,Transient, Category = "Health")
		int32 MaxHealth;
	UPROPERTY(BlueprintReadWrite, Category = "Health")
		int32 MaxHealthA;
	UPROPERTY(BlueprintReadWrite, Category = "Health")
		float MaxHealthM;
	UPROPERTY( BlueprintReadWrite, Category = "Mana")
		int32 Mana;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Transient, Category = "Mana")
		int32 MaxMana;
	UPROPERTY(BlueprintReadWrite, Category = "Mana")
		int32 MaxManaA;
	UPROPERTY(BlueprintReadWrite, Category = "Mana")
		float MaxManaM;
		//attack
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Transient, Category = "AttackDamage")
		int32 AttackDamage;
	UPROPERTY(BlueprintReadWrite, Category = "AttackDamage")
		int32 AttackDamageA;
	UPROPERTY(BlueprintReadWrite, Category = "AttackDamage")
		float AttackDamageM;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Transient, Category = "AttackDamage")
		float DamagePerSecond;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Transient, Category = "AttackSpeed")
		int32 AttackSpeed;
	UPROPERTY(BlueprintReadWrite, Category = "AttackSpeed")
		int32 AttackSpeedA;
	UPROPERTY(BlueprintReadWrite, Category = "AttackSpeed")
		float AttackSpeedM;
	UPROPERTY(BlueprintReadWrite, Category = "AttackSpeed")
		float PreAttack;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Transient, Category = "AttackSpeed")
		float AttackTime;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Transient, Category = "AttackSpeed")
		float PunchRate;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Transient, Category = "AttackRange")
		int32 AttackRange;
	UPROPERTY(BlueprintReadWrite, Category = "AttackRange")
		int32 AttackRangeA;
	UPROPERTY(BlueprintReadWrite, Category = "AttackRange")
		int32 MeleeAttackRangeA;
	UPROPERTY(BlueprintReadWrite, Category = "AttackRange")
		float AttackRangeM;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttackRange")
		bool ISRange;//is heroes ranged(true) or melee(false)
		//Magic
	UPROPERTY(BlueprintReadWrite, Category = "MagicPower")
		int32 MagicPowerA;
	UPROPERTY(BlueprintReadWrite, Category = "MagicPower")
		float MagicPowerM;
	UPROPERTY(BlueprintReadWrite, Category = "MagicRange")
		int32 MagicRangeA;
	UPROPERTY(BlueprintReadWrite, Category = "MagicRange")
		float MagicRangeM;
	UPROPERTY(BlueprintReadWrite, Category = "CastTime")
		int32 CastTimeA;
	UPROPERTY(BlueprintReadWrite, Category = "CastTime")
		float CastTimeM;
	UPROPERTY(BlueprintReadWrite, Category = "CoolDownTime")
		int32 CoolDownTimeA;
	UPROPERTY(BlueprintReadWrite, Category = "CoolDownTime")
		float CoolDownTimeM;
		//Armor&&resist
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Transient, Category = "Armor")
		int32 Armor;
	UPROPERTY(BlueprintReadWrite, Category = "Armor")
		int32 ArmorA;
	UPROPERTY(BlueprintReadWrite, Category = "Armor")
		float ArmorM;
	UPROPERTY(BlueprintReadWrite, Category = "Armor")
		int32 NegateArmorA;
	UPROPERTY(BlueprintReadWrite, Category = "Armor")
		float NegateArmorM;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Transient, Category = "Resist")
		float PhysicMultiplier;
	UPROPERTY(BlueprintReadWrite, Category = "Resist")
		float PhysicMultiplierM;
	UPROPERTY(BlueprintReadWrite, Category = "Resist")
		float MagicMultiplierM;
		//base stats
	UPROPERTY( BlueprintReadWrite,Transient, Category = "Stats")
		int32 RedSt;
	UPROPERTY( BlueprintReadWrite, Transient,Category = "Stats")
		int32 GreenSt;
	UPROPERTY( BlueprintReadWrite, Transient,Category = "Stats")
		int32 BlueSt;
	UPROPERTY(BlueprintReadWrite, Category = "Stats")
		int32 RedStA;
	UPROPERTY( BlueprintReadWrite, Category = "Stats")
		int32 GreenStA;
	UPROPERTY( BlueprintReadWrite, Category = "Stats")
		int32 BlueStA;
	UPROPERTY( BlueprintReadWrite, Category = "Stats")
		float RedStM;
	UPROPERTY( BlueprintReadWrite, Category = "Stats")
		float GreenStM;
	UPROPERTY( BlueprintReadWrite, Category = "Stats")
		float BlueStM;
		//expirience
	UPROPERTY(BlueprintReadWrite, Category = "Experience")
		int32 Exp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Experience")
		int32 lvl;
	UPROPERTY(BlueprintReadWrite, Category = "Experience")
		int32 LvlExp;
	//!!!!!!!!!!!!!!!!BAAAAAAAAAAAAAAAAAASSSSSSSSSSSEEEEEEEEEEE
	//health and mana
	UPROPERTY(BlueprintReadWrite, Category = "Health")
		int32 BaseMaxHealthA;
	UPROPERTY(BlueprintReadWrite, Category = "Health")
		float BaseMaxHealthM;
	UPROPERTY(BlueprintReadWrite, Category = "Mana")
		int32 BaseMaxManaA;
	UPROPERTY(BlueprintReadWrite, Category = "Mana")
		float BaseMaxManaM;
	//attack
	UPROPERTY(BlueprintReadWrite, Category = "AttackDamage")
		int32 BaseAttackDamageA;
	UPROPERTY(BlueprintReadWrite, Category = "AttackDamage")
		float BaseAttackDamageM;
	UPROPERTY(BlueprintReadWrite, Category = "AttackSpeed")
		int32 BaseAttackSpeedA;
	UPROPERTY(BlueprintReadWrite, Category = "AttackSpeed")
		float BaseAttackSpeedM;
	UPROPERTY(BlueprintReadWrite, Category = "AttackRange")
		int32 BaseAttackRangeA;
	UPROPERTY(BlueprintReadWrite, Category = "AttackRange")
		int32 BaseMeleeAttackRangeA;
	UPROPERTY(BlueprintReadWrite, Category = "AttackRange")
		float BaseAttackRangeM;
	UPROPERTY(BlueprintReadWrite, Category = "MagicPower")
		int32 BaseMagicPowerA;
	UPROPERTY(BlueprintReadWrite, Category = "MagicPower")
		float BaseMagicPowerM;
	UPROPERTY(BlueprintReadWrite, Category = "MagicRange")
		int32 BaseMagicRangeA;
	UPROPERTY(BlueprintReadWrite, Category = "MagicRange")
		float BaseMagicRangeM;
	UPROPERTY(BlueprintReadWrite, Category = "CastTime")
		int32 BaseCastTimeA;
	UPROPERTY(BlueprintReadWrite, Category = "CastTime")
		float BaseCastTimeM;
	UPROPERTY(BlueprintReadWrite, Category = "CoolDownTime")
		int32 BaseCoolDownTimeA;
	UPROPERTY(BlueprintReadWrite, Category = "CoolDownTime")
		float BaseCoolDownTimeM;
	//Armor&&resist
	UPROPERTY(BlueprintReadWrite, Category = "Armor")
		int32 BaseArmorA;
	UPROPERTY(BlueprintReadWrite, Category = "Armor")
		float BaseArmorM;
	UPROPERTY(BlueprintReadWrite, Category = "Armor")
		int32 BaseNegateArmorA;
	UPROPERTY(BlueprintReadWrite, Category = "Armor")
		float BaseNegateArmorM;
	UPROPERTY(BlueprintReadWrite, Category = "Resist")
		float BasePhysicMultiplierM;
	UPROPERTY(BlueprintReadWrite, Category = "Resist")
		float BaseMagicMultiplierM;
	//base stats
	UPROPERTY(BlueprintReadWrite, Category = "Stats")
		int32 BaseRedStA;
	UPROPERTY(BlueprintReadWrite, Category = "Stats")
		int32 BaseGreenStA;
	UPROPERTY(BlueprintReadWrite, Category = "Stats")
		int32 BaseBlueStA;
	UPROPERTY(BlueprintReadWrite, Category = "Stats")
		float BaseRedStM;
	UPROPERTY(BlueprintReadWrite, Category = "Stats")
		float BaseGreenStM;
	UPROPERTY(BlueprintReadWrite, Category = "Stats")
		float BaseBlueStM;

		//extra
	UPROPERTY(BlueprintReadWrite, Category = "EnemyVar")
		int32 FireStacks;
	UPROPERTY(BlueprintReadWrite, Category = "EnemyVar")
		float ElectricStacks;
	TArray<float> SkillCDTimes;
	TArray<int32> SkillLevel;
		//weapon section
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
		int32 NumOfWeapon;
	TArray<int32> WeapType;
	TArray<bool> HaveWeap;
	TArray<class InvWeapon*> WeapSlots;
		//effects section
	float TimeToUpdate;
	class Effects *Base;
	Effects *LastPositive;
	Effects *LastPermanent;
	Effects* AddNewEffect(bool Visual, bool Permanent, bool Positive,enum class NameEffects Number, float Time = 1.0f);
	Effects* FindName(enum class NameEffects Number);
	void CalcEffects(float Delta);
	void CalcOneEffect(Effects *iter,float Delta);
	void DeleteEffect(Effects* iter);
		//anim values
	 UPROPERTY(BlueprintReadWrite,Category="Animations")
		bool OnePunch = false;
	 UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Animations")
		 float PunchTime=0.8f;
		//blueprints functions
	UFUNCTION(BlueprintImplementableEvent, Category = "HealthBar")
		void UpdateHealthBar();
			//MUST BE DELETED
	UFUNCTION(BlueprintImplementableEvent, Category = "DEBUG")
		void SpawnMesh(FVector a);
		//influence functions
	UFUNCTION(BlueprintCallable, Category = "Attack")
		void CalculateAttack( ACommonAncestor *Victim, TArray<int32> flags)
	{
		Victim->Health -= AttackDamage;
		if (Victim->Health < 0)
			Victim->Destroy();
		Victim->UpdateHealthBar();
	};
	UFUNCTION(BlueprintCallable, Category = "Attack")
		void DoAttack(ACommonAncestor *Victim);
	UFUNCTION(BlueprintCallable, Category = "Self")
		void Dead();
	//update functions
	UFUNCTION(BlueprintCallable, Category = "Self")
		void InitStats();//init commit
	UFUNCTION(BlueprintCallable, Category = "Self")
		void UpdateAll() ;
	UFUNCTION(BlueprintCallable, Category = "Self")
		void ResetStats();
	UFUNCTION(BlueprintCallable, Category = "Self")
		void UpdateExp() ;
	//effects functions
	UFUNCTION(BlueprintCallable, Category = "Self")
		void ChangePhys(TArray<int32>flags) {};
	UFUNCTION(BlueprintCallable, Category = "Self")
		void ChangeMagic(TArray<int32>flags) {};
	UFUNCTION(BlueprintCallable, Category = "Self")
		void ChangeResist(TArray<int32>flags) {};
	UFUNCTION(BlueprintCallable, Category = "Self")
		void ChangeRange(TArray<int32>flags) {};
	UFUNCTION(BlueprintCallable, Category = "Self")
		void ChangeHealth(TArray<int32>flags) {};

	
	
	//just support variables
	int32 i;
	float EffectiveCD;
	//*/
};
