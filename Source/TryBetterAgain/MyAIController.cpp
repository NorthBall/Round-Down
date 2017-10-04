// Fill out your copyright notice in the Description page of Project Settings.

#include "MyAIController.h"
#include "TryBetterAgainPlayerController.h"
#include "AI/Navigation/NavigationSystem.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "TryBetterAgainCharacter.h"
#include "MyProjectile.h"
#include "AI.h"

AMyAIController::AMyAIController()
{
	
}
void AMyAIController::BeginPlay()
{
	Super::BeginPlay();
	Possess(GetWorld()->SpawnActor<ATryBetterAgainCharacter>(PawnClass, FVector(-490.f, -86.f, 293.f), FRotator::ZeroRotator));
}
