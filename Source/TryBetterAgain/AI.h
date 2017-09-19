// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CommonAncestor.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AI.generated.h"

UCLASS()
class TRYBETTERAGAIN_API AAI : public ACommonAncestor
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAI();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
};
