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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		int32 Health;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		int32 Mana;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		int32 MaxHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		int32 MaxMana;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		int32 AttackDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		int32 AttackSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		int32 AttackRange;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Transient, Category = "Damage")
		float DamagePerSecond;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		int32 MagicPower;//multiply magic skills
	
	UFUNCTION(BlueprintCallable, Category = "Damage")
		void CalculateAttack( ACommonAncestor *Victim, TArray<int32> flags)
	{
		Victim->Health -= AttackDamage;
	};

	
	
};
