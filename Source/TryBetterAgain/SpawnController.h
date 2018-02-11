// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "SpawnController.generated.h"

/**
 * 
 */
UCLASS()
class TRYBETTERAGAIN_API ASpawnController : public AAIController
{
	GENERATED_BODY()
public:
		TDoubleLinkedList <class AAI*> Bots;
		void SpawnBots() {};
	
	
};
