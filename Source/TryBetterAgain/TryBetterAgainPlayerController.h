// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TryBetterAgainPlayerController.generated.h"

UCLASS()
class ATryBetterAgainPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATryBetterAgainPlayerController();
	void OnSetDestinationPressed();
	void OnSetDestinationReleased();
	void OnSpellCastPressed();
	void OnSpellCastReleased();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
		bool bAttack;

	bool leftClicked;

	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<class AMyProjectile> MyProjectileBP;

protected:
	/** True if the controlled character should navigate to the mouse cursor. */
	bool bClicked = false;

	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	// End PlayerController interface

	/** Resets HMD orientation in VR. */
	void OnResetVR();

	/** Navigate player to the current mouse cursor location. */
	void OnClicked();

	/** Navigate player to the current touch location. */
	void MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location);
	
	/** Navigate player to the given world location. */
	void SetNewMoveDestination(const FVector DestLocation);
	
	void Attack();

	void DontAttack();

	void CastSpell();

	FVector Tehnika100TochekKorsuna(FVector to, int range, FVector from);
		
	/** Input handlers for SetDestination action. */
	
};


