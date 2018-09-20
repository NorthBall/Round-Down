// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Lance.generated.h"

UCLASS()
class TRYBETTERAGAIN_API ALance : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALance();


	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	/** Sphere collision component */
	UPROPERTY(EditAnywhere, Category = Projectile)
		class USphereComponent* CollisionComp;

	/** Projectile movement component */
	UPROPERTY(EditAnywhere, Category = Movement)
		class UProjectileMovementComponent* ProjectileMovement;

	/** called when projectile hits something */
	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	
	class ATryBetterAgainCharacter* Hero;
	class ACommonAncestor *victim;
};