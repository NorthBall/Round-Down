// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "TryBetterAgainPlayerController.h"

#include "MyAIController.h"
#include "AI/Navigation/NavigationSystem.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "TryBetterAgainCharacter.h"
#include "MyProjectile.h"
#include "AI.h"
#include "CommonAncestor.h"
#include "GameFramework/Character.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/DecalComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Materials/Material.h"

ATryBetterAgainPlayerController::ATryBetterAgainPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
	
	
	/*Dumb = CreateDefaultSubobject<UNavMovementComponent>(TEXT("Dobby"));
	Dumb->UpdateNavAgent(this);
	AIMovement= CreateDefaultSubobject<UPathFollowingComponent>(TEXT("MovementComp"));
	AIMovement->SetMovementComponent(Dumb);*/
}

void ATryBetterAgainPlayerController::BeginPlay()
{
	Super::BeginPlay();
	CameraSpeed = 4;
	CameraUp = 1500;
	CameraDown = 600;
	NPK = GetWorld()->SpawnActor<AMyAIController>(AIKClass, FVector(-490.f, -86.f, 392.f), FRotator::ZeroRotator);
	NPK->MyOwner = this;
	OursPawn=Cast<ATryBetterAgainCharacter>(NPK->GetPawn());
	SetViewTarget(OursPawn);
	if (OursPawn == NULL)
	{
		UE_LOG(LogTemp, Warning, TEXT("Korsun is absolute zero  iq"));
	}
	else
		UE_LOG(LogTemp, Warning, TEXT("Korsun is onehugredandforty  iq"));
	SetViewTargetWithBlend(OursPawn);
	
}


void ATryBetterAgainPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	

	// keep updating the destination every tick while desired
	if (bClicked) {
		FHitResult Hit;
		GetHitResultUnderCursor(ECC_Visibility, false, Hit);

		if (Hit.bBlockingHit) {
			victim = Cast<AAI>(Hit.GetActor());
			if (victim != nullptr) {
				is_gonna_attacking = true;
				UE_LOG(LogTemp, Warning, TEXT("Set victim"));
			}
			else {
				is_gonna_attacking = false;
				DontAttack();
				UE_LOG(LogTemp, Warning, TEXT("Move destination to HZ"));
				SetNewMoveDestination(Hit.ImpactPoint);
			}
		}
	}

	if (is_gonna_attacking && !bAttack ) {
		//UE_LOG(LogTemp, Warning, TEXT("In is_gonna_attacking"));
		
		if (OursPawn != nullptr) {
			float const Distance = FVector::Dist2D(victim->GetActorLocation(), OursPawn->GetActorLocation());
			UE_LOG(LogTemp, Warning, TEXT("Korsun is %f  iq"), Distance- OursPawn->AttackRange);
			if (Distance > OursPawn->AttackRange) {
				//victim->SpawnMesh(destination);
				if (bClicked)
					NPK->MoveToActor(victim, OursPawn->AttackRange);
			
			}
			else {
				if (OursPawn->FacedToEnemy(victim->GetActorLocation())){
					Attack();
					is_gonna_attacking = false;
				}
				//UE_LOG(LogTemp, Warning, TEXT("Unset is_gonna_attacking"));
			}
		}
		else
			is_gonna_attacking = false;
	}
	
	if (bAttack) {
		all_time += DeltaTime;
		if (all_time >= 1) {
			TArray<int32> flags;
			OursPawn->CalculateAttack(victim, flags);
			all_time = 0;
		}
	}
	//Zoom
	{
		if (bZooming == 1)
		{
			ZoomFactor += CameraSpeed * DeltaTime;         //Zoom in over half a second
		}
		else if (bZooming == -1)
		{
			ZoomFactor -= CameraSpeed * DeltaTime;        //Zoom out over a quarter of a second
		}
		ZoomFactor = FMath::Clamp<float>(ZoomFactor, 0.0f, 1.0f);
		//Blend our camera's FOV and our SpringArm's length based on ZoomFactor
		OursPawn->TopDownCameraComponent->FieldOfView = FMath::Lerp<float>(90.0f, 60.0f, ZoomFactor);
		OursPawn->CameraBoom->TargetArmLength = FMath::Lerp<float>(CameraUp, CameraDown, ZoomFactor);
		bZooming = 0;
	}
}

void ATryBetterAgainPlayerController::CastSpell()
{
	FHitResult Hit;
	GetHitResultUnderCursor(ECC_Visibility, false, Hit);
	if (Hit.bBlockingHit) {
		
		OursPawn->FacedToEnemy(Hit.ImpactPoint);
		UWorld* const World = GetWorld();
		FRotator deltaRotate = (Hit.ImpactPoint - OursPawn->GetActorLocation() + FVector(0, 0, OursPawn->GetActorLocation().Z - Hit.ImpactPoint.Z)).Rotation();
		FVector location = OursPawn->GetActorLocation() + OursPawn->GetActorForwardVector() * 50;
		AMyProjectile* Projectile = World->SpawnActor<AMyProjectile>(MyProjectileBP, location, deltaRotate);
		Projectile->owner = OursPawn;
	}
}

void ATryBetterAgainPlayerController::Attack()
{
	bAttack = true;
}

void ATryBetterAgainPlayerController::DontAttack()
{
	bAttack = false;
}

void ATryBetterAgainPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();
	struct FInputActionBinding* Consume;

	Consume = &InputComponent->BindAction("SetDestination", IE_Pressed, this, &ATryBetterAgainPlayerController::OnSetDestinationPressed);
	Consume->bConsumeInput = false;
	InputComponent->BindAction("SetDestination", IE_Released, this, &ATryBetterAgainPlayerController::OnSetDestinationReleased).bConsumeInput=false;

	Consume = &InputComponent->BindAction("CastSpell", IE_Pressed, this, &ATryBetterAgainPlayerController::OnSpellCastPressed);
	Consume->bConsumeInput = false;
	InputComponent->BindAction("CastSpell", IE_Released, this, &ATryBetterAgainPlayerController::OnSpellCastReleased).bConsumeInput = false;
	InputComponent->BindAction("ZoomIn", IE_Pressed, this, &ATryBetterAgainPlayerController::ZoomIn);
	InputComponent->BindAction("ZoomOut", IE_Pressed, this, &ATryBetterAgainPlayerController::ZoomOut);
}

void ATryBetterAgainPlayerController::OnResetVR()
{
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}


void ATryBetterAgainPlayerController::MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	FVector2D ScreenSpaceLocation(Location);

	// Trace to see what is under the touch location
	FHitResult HitResult;
	GetHitResultAtScreenPosition(ScreenSpaceLocation, CurrentClickTraceChannel, true, HitResult);
	if (HitResult.bBlockingHit)
	{
		// We hit something, move there
		SetNewMoveDestination(HitResult.ImpactPoint);
	}
}

void ATryBetterAgainPlayerController::SetNewMoveDestination(const FVector DestLocation)
{
	
	
	if (OursPawn)
	{
		UNavigationSystem* const NavSys = GetWorld()->GetNavigationSystem();
		float const Distance = FVector::Dist(DestLocation, OursPawn->GetActorLocation());
		
		// We need to issue move command only if far enough in order for walk animation to play correctly
		if (NavSys )
		{
			//UE_LOG(LogTemp, Warning, TEXT("distance is %f"), Distance);
			//NavSys->SimpleMoveToLocation(this, DestLocation);
			NPK->MoveToLocation(DestLocation, 1.0f);
		}
	}
}

void ATryBetterAgainPlayerController::OnSetDestinationPressed()
{
	// set flag to keep updating destination until released
	bClicked = true;
}

void ATryBetterAgainPlayerController::OnSetDestinationReleased()
{
	// clear flag to indicate we should stop updating the destination
	bClicked = false;
}

void ATryBetterAgainPlayerController::OnSpellCastPressed()
{
	// set flag to keep updating destination until released
	leftClicked = true;
}

void ATryBetterAgainPlayerController::OnSpellCastReleased()
{
	// set flag to keep updating destination until released
	CastSpell();
	leftClicked = false;
}
void ATryBetterAgainPlayerController::ZoomIn()
{
	bZooming = 1;
}

void ATryBetterAgainPlayerController::ZoomOut()
{
	bZooming = -1;
}