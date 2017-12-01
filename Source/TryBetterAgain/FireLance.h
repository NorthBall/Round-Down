// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MotherOfProjectiles.h"
#include "FireLance.generated.h"

/**
 * 
 */
UCLASS()
class TRYBETTERAGAIN_API AFireLance : public AMotherOfProjectiles
{
	GENERATED_BODY()
public:
	AFireLance();
	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	virtual void BeginPlay() override;
	
	
	
};
