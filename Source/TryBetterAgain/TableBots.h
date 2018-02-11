// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Engine/DataTable.h"
#include "TableBots.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct TRYBETTERAGAIN_API FTableBots: public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
public:
	FTableBots();
	~FTableBots();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Health;
};
