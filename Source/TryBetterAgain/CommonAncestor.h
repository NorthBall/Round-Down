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
	//Stats area
	//health and mana
	UPROPERTY(BlueprintReadWrite, Category = "Health")
		int32 Health;
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
		int32 ISRange;//is heroes ranged(true) or melee(false)
		//Magic
	UPROPERTY(BlueprintReadWrite, Category = "MagicPower")
		int32 MagicPowerA;
	UPROPERTY(BlueprintReadWrite, Category = "MagicPower")
		float MagicPowerM;
	UPROPERTY(BlueprintReadWrite, Category = "MagicRange")
		int32 MagicRangeA;
	UPROPERTY(BlueprintReadWrite, Category = "MagicRange")
		float MagicRangeM;
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

		//extra
	//weapon section
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
		int32 NumOfWeapon;
	TArray<int32> WeapType;
	TArray<bool> HaveWeap;
	TArray<class InvWeapon*> WeapSlots;
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
	void InitStats();//init commit
	UFUNCTION(BlueprintCallable, Category = "Self")
		void UpdateAll() ;
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
