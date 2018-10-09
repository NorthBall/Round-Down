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
	//ROTATION area
	/*FRotator DestRotation;
	bool NeedRotation = false;
	void Rotate();
	void ReqForRotate(FVector Dest);*/
//*
	//effects
	float InvulTime;
	//Stats area
		//primal stats
	UPROPERTY(BlueprintReadWrite, Category = "Params")
		TMap<FString, int32> BaseA;// стандартные значения параметров. Нужны только для обновления
	UPROPERTY(BlueprintReadWrite, Category = "Params")
		TMap<FString, float> BaseM;
	UPROPERTY(BlueprintReadWrite, Category = "Params")
		TMap<FString, int32> RealA;//реальные значения параметров. Нужны
	UPROPERTY(BlueprintReadWrite, Category = "Params")
		TMap<FString, float> RealM; 
		//secondary stats
		//health and mana
	UPROPERTY(BlueprintReadWrite, Category = "Health")
		int32 Health;
	UPROPERTY(BlueprintReadWrite,VisibleAnywhere,Transient, Category = "Health")
		int32 MaxHealth;
	UPROPERTY( BlueprintReadWrite, Category = "Mana")
		int32 Mana;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Transient, Category = "Mana")
		int32 MaxMana;
		//attack
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Transient, Category = "AttackDamage")
		int32 AttackDamage;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Transient, Category = "AttackDamage")
		float DamagePerSecond;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Transient, Category = "AttackSpeed")
		int32 AttackSpeed;
	UPROPERTY(BlueprintReadWrite, Category = "AttackSpeed")
		float PreAttack;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Transient, Category = "AttackSpeed")
		float AttackTime;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Transient, Category = "AttackSpeed")
		float PunchRate;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Transient, Category = "AttackRange")
		int32 AttackRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttackRange")
		bool ISRange;//is heroes ranged(true) or melee(false)
		//Magic
		//Armor&&resist
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Transient, Category = "Armor")
		int32 Armor;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Transient, Category = "Resist")
		float PhysicMultiplier;
		//base stats
	UPROPERTY( BlueprintReadWrite,Transient, Category = "Stats")
		int32 RedSt;
	UPROPERTY( BlueprintReadWrite, Transient,Category = "Stats")
		int32 GreenSt;
	UPROPERTY( BlueprintReadWrite, Transient,Category = "Stats")
		int32 BlueSt;
		//movement
	UPROPERTY(BlueprintReadWrite, Category = "Movement")
		float MovementSpeed;
		float MovementRotate;
		//expirience
	UPROPERTY(BlueprintReadWrite, Category = "Experience")
		int32 Exp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Experience")
		int32 lvl;
	UPROPERTY(BlueprintReadWrite, Category = "Experience")
		int32 LvlExp;
	
		//extra
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
	class Effects *BaseInfluence;
	Effects *BaseTemporal;
	Effects *BasePermanent;
	void AddNewEffect(bool Influent, Effects* iter);
	Effects* FindName(enum class NameEffects Number, bool OnlyInfluence = false);
	void CalcEffects(float Delta);
	void DeleteEffect(Effects* iter);
		//anim values
	 UPROPERTY(BlueprintReadWrite,Category="Animations")
		bool OnePunch = false;
	 UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Animations")
		 float PunchTime=0.8f;
		//blueprints functions
	UFUNCTION(BlueprintImplementableEvent, Category = "HealthBar")
		void UpdateHealthBar();
			
		//influence functions
	UFUNCTION(BlueprintCallable, Category = "Attack")
		void DoAttack(ACommonAncestor *Victim);
	UFUNCTION(BlueprintCallable, Category = "Self")
		virtual void Dead();
	//support
		void DealDamage(ACommonAncestor *Victim, int Damage, enum class DamageType Type);
	//update functions
	UFUNCTION(BlueprintCallable, Category = "Self")
		void InitStats();//init commit
	UFUNCTION(BlueprintCallable, Category = "Self")
		void UpdateAll() ;
	UFUNCTION(BlueprintCallable, Category = "Self")
		void ResetStats();
	UFUNCTION(BlueprintCallable, Category = "Self")
		void UpdateExp() ;
		
	//just support variables
	int32 i;
	float EffectiveCD;
	//*/
};
