// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "MyAIController.generated.h"

/**
 * 
 */
UCLASS()
class TRYBETTERAGAIN_API AMyAIController : public AAIController
{
	GENERATED_BODY()
	

public:
	AMyAIController();
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	class ATryBetterAgainPlayerController* MyOwner;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<class ATryBetterAgainCharacter> PawnClass;
	virtual void BeginPlay() override;
};

