// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "InvWeapon.h"
#include "GameFramework/Character.h"
#include "CommonAncestor.generated.h"


UCLASS()
class TRYBETTERAGAIN_API ACommonAncestor : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACommonAncestor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	//effects
	float InvulTime;
	//current stats
	UPROPERTY(BlueprintReadWrite, Category = "Stats")
		int32 Health;
	UPROPERTY( BlueprintReadWrite, Category = "Stats")
		int32 Mana;
		//attack
	UPROPERTY( BlueprintReadWrite, Category = "Stats")
		float PhysDamageBuffM;
	UPROPERTY(BlueprintReadWrite, Category = "Stats")
		float AttackSpeedBuffM;	
	UPROPERTY(BlueprintReadWrite, Category = "Stats")
		float AttackRangeBuffM;
		//Magic
	UPROPERTY(BlueprintReadWrite, Category = "Stats")
		float MagicPowerBuffM;
	UPROPERTY(BlueprintReadWrite, Category = "Stats")
		float MagicRangeBuffM;
		//resist
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Transient, Category = "Phys")
		float ArmorBuffM;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Transient, Category = "Phys")
		float NegateArmorBuffM;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Transient, Category = "Phys")
		float PhysCoeffBuffM;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Transient, Category = "Phys")
		float MagicCoeffBuffM;
		//expirience
	UPROPERTY(BlueprintReadWrite, Category = "Stats")
		int32 Exp;//expirience
		//extra
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		int32 ISRange;//is heroes melee or ranged
	//base stats
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		int32 MaxHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		int32 MaxMana;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		int32 RedSt;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		int32 GreenSt;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		int32 BlueSt;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		int32 BaseDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		int32 BaseAttackSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		float PreAtak;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		int32 BaseRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		int32 BaseMagicPower;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		int32 BaseMagicRange;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		int32 BaseArmor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		int32 BasePhysCoef;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		int32 BaseMagicCoef;
	
	//shown stats
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		int32 lvl;
	//support information
		//attack
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Transient, Category = "Stats")
		int32 AttackDamage;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Transient, Category = "Stats")
		float PhysDamage;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Transient, Category = "Stats")
		int32 AttackSpeed;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Transient, Category = "Stats")
		float AttackTime;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Transient, Category = "Damage")
		float DamagePerSecond;	
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Transient, Category = "Stats")
		int32 AttackRange;
		//magic
	UPROPERTY(BlueprintReadWrite, Category = "Stats")
		int32 MagicPower;//multiply magic skills
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Transient, Category = "Stats")
		int32 MagicRange;
		//resist	
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Transient, Category = "Phys")
		float Armor;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Transient, Category = "Phys")
		float NegateArmor;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Transient, Category = "Phys")
		float PhysCoeff;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Transient, Category = "Phys")
		float MagicCoeff;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Transient, Category = "Exp")
		int32 LvlExp;//for up
	//weapon section
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
		int32 NumOfWeapon;
	TArray<int32> WeapType;
	TArray<bool> HaveWeap;
	TArray<class InvWeapon*> WeapSlots;
	//std::vector <class InvWeapon> a;
	//inside values
	TArray<int32> bleed;
	 int32 BleedNum;
	 float BleedTime;
	 //anim values
	 UPROPERTY(BlueprintReadWrite,Category="Animations")
	 bool OnePunch = false;
	//blueprints functions
	UFUNCTION(BlueprintImplementableEvent, Category = "HealthBar")
		void UpdateHealthBar();
	UFUNCTION(BlueprintImplementableEvent, Category = "HealthBar")
		void SpawnMesh(FVector a);
	//influence functions
	UFUNCTION(BlueprintCallable, Category = "Damage")
		void CalculateAttack( ACommonAncestor *Victim, TArray<int32> flags)
	{
		Victim->Health -= AttackDamage;
		if (Victim->Health < 0)
			Victim->Destroy();
		Victim->UpdateHealthBar();
	};
	UFUNCTION(BlueprintCallable, Category = "Damage")
		void Ataka(ACommonAncestor *Victim);
	UFUNCTION(BlueprintCallable, Category = "Self")
		void BleedDamage(int32 Damage);
	UFUNCTION(BlueprintCallable, Category = "Self")
		void Dead();
	//recalculate functions
	UFUNCTION(BlueprintCallable, Category = "Self")
		void UpdateAll() ;
	UFUNCTION(BlueprintCallable, Category = "Self")
		void UpdateAttackDamage();
	UFUNCTION(BlueprintCallable, Category = "Self")
		void UpdateAttackSpeed();
	UFUNCTION(BlueprintCallable, Category = "Self")
		void UpdateAttackRange();
	UFUNCTION(BlueprintCallable, Category = "Self")
		void UpdateMagicPower() ;
	UFUNCTION(BlueprintCallable, Category = "Self")
		void UpdateMagicRange();
	UFUNCTION(BlueprintCallable, Category = "Self")
		void UpdateResist() ;
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

	
	
	
};
