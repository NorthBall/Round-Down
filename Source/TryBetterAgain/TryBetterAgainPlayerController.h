// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.


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
	bool Korsuns=true;
	bool leftClicked;

	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<class AMyProjectile> MyProjectileBP;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement)
		class AMyAIController* NPK;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement)
		class ATryBetterAgainCharacter*  OursPawn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<class AMyAIController> AIKClass;
	/*UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
		class UPathFollowingComponent* AIMovement;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
				class UNavMovementComponent* Dumb;*/
	UFUNCTION(BlueprintImplementableEvent, Category = "HealthBar")
		void SpawnMesh(FVector a);


	/** True if the controlled character should navigate to the mouse cursor. */
	bool bClicked = false;

	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	virtual void BeginPlay() override;
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
	 bool is_gonna_attacking = false;
	 class AAI* victim;
	 float all_time = 0;
	 class ATryBetterAgainCharacter* MyCharacter;
		
	/** Input handlers for SetDestination action. */
	
};


