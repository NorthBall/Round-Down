// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <vector>
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
	UPROPERTY( BlueprintReadWrite, Category = "Stats")
		int32 AttackDamageBuffM;//in percent
	UPROPERTY(BlueprintReadWrite, Category = "Stats")
		int32 AttackSpeedBuffM;//in perecent	
	UPROPERTY(BlueprintReadWrite, Category = "Stats")
		int32 AttackRangeBuffM;//in percent
	UPROPERTY(BlueprintReadWrite, Category = "Stats")
		int32 MagicRangeBuffM;//in percent
	UPROPERTY(BlueprintReadWrite, Category = "Stats")
		int32 Exp;//expirience
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
		int32 BaseMagicPower;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		int32 BaseMagicRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		int32 BaseRange;
	//shown stats
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		int32 lvl;
	//support information
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Transient, Category = "Damage")
		float DamagePerSecond;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		int32 LvlExp;//for up
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		int32 AttackDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		int32 AttackRange;
	UPROPERTY(BlueprintReadWrite, Category = "Stats")
		int32 MagicPower;//multiply magic skills
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		int32 MagicRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		int32 AttackSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		int32 AttackTime;

	//inside values
	TArray<int32> bleed;
	 int32 BleedNum;
	 float BleedTime;
	 //anim values
	 UPROPERTY(BlueprintReadWrite,Category="Animations")
	 bool OnePunch = false;
	//blueprints functions
	UFUNCTION(BlueprintImplementableEvent, Category = "HealthBar")
		void UpdateHealth();
	UFUNCTION(BlueprintImplementableEvent, Category = "HealthBar")
		void SpawnMesh(FVector a);
	//influence functions
	UFUNCTION(BlueprintCallable, Category = "Damage")
		void CalculateAttack( ACommonAncestor *Victim, TArray<int32> flags)
	{
		Victim->Health -= AttackDamage;
		if (Victim->Health < 0)
			Victim->Destroy();
		Victim->UpdateHealth();
	};
	UFUNCTION(BlueprintCallable, Category = "Damage")
		void Ataka(ACommonAncestor *Victim);
	UFUNCTION(BlueprintCallable, Category = "Self")
		void BleedDamage(int32 Damage);
	UFUNCTION(BlueprintCallable, Category = "Self")
		void Dead();
	
	
	
};
