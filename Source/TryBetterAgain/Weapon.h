// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

UCLASS()
class TRYBETTERAGAIN_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeapon();

	//Weapon's stats
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		 int WeaponGroup;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Attack;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
