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
	virtual void Tick(float DeltaSeconds) override;
	virtual void BeginPlay() override;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		class UParticleSystemComponent* LanceSelf;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		UParticleSystemComponent* Explosion;
	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	
	
	bool Exploding = false;
	float TimeToDissapear=1.0f;
	void Changes();
	
};
