// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FireMeteor.generated.h"

UCLASS()
class TRYBETTERAGAIN_API AFireMeteor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFireMeteor();
	class ATryBetterAgainCharacter* owner;
	float TimeToRelease;
	USceneComponent *Root;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
