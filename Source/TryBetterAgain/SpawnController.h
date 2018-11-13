// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
//#include "Runtime/Engine/Classes/Engine/DataTable.h"
#include "SpawnController.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class TRYBETTERAGAIN_API ASpawnController : public AAIController
{
	GENERATED_BODY()
public:
		TDoubleLinkedList <class AAI*> Bots;
		UFUNCTION(BlueprintCallable)
		void SpawnBots () ;
		UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="WhatSpawn")
		TArray<TSubclassOf<AAI>> BotType;
		UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "WhatSpawn")
		TArray<int32> BotNumber;
		UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "WhatSpawn")
		TArray<int32> Botlvl;
	/*	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UDataTable * BotsTable;
		//inputdata
		TLinkedList<enum class BotType> TypeToSpawn;
		TLinkedList<int32> LvlToSpawn;
		//suppoting
		TArray<FName> RowsFName;*/
	
	
};
