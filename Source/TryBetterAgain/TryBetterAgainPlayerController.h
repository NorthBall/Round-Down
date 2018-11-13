// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.


#include "CoreMinimal.h"
#include "Effects.h"
#include "GameFramework/PlayerController.h"
#include "TryBetterAgainPlayerController.generated.h"

UCLASS()
class ATryBetterAgainPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	//skill area
	void FireMeteor();
	void FireQueue();
	void FireBlink();
	void FireLance();
	void FireAura();

	ATryBetterAgainPlayerController();
	void OnSetDestinationPressed();
	void OnSetDestinationReleased();
	void OnSpellCastPressed();
	void OnSpellCastReleased();
	void SetPauseMenu();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<class UUserWidget> WidgetClass;
	UUserWidget* PauseMenu;
	//doing area
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
		bool bAttack;
	ESkill State;
	float WaitTime;
	float FullTime;
	FHitResult Direct;
	float DoSkill(ESkill State,float Time);
	void DoStop();
	void CancelSkill();
	//attack area
	float Distance;
	class AAI *oldVictim;
	bool IsMoved;


	bool leftClicked;

	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<class AMyProjectile> MyProjectileBP;//стрела
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement)
		class AMyAIController* NPK; //реальный контроллер
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement)
		class ATryBetterAgainCharacter*  OursPawn;//рпеальная моделька
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<class AMyAIController> AIKClass;
	/*UFUNCTION(BlueprintImplementableEvent, Category = "HealthBar")
		void SpawnMesh(FVector a);
		Показать точку направления*/


	/** True if the controlled character should navigate to the mouse cursor. */
	bool bClicked = false;

	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	virtual void BeginPlay() override;
	// End PlayerController interface


	

	
	
	/** Navigate player to the given world location. */
	void SetNewMoveDestination(const FVector DestLocation);
	
	void Attack();

	void DontAttack();

	void CastSpell();

	 bool is_gonna_attacking = false;
	 class AAI* victim;
	 float all_time = 0;
	 class ATryBetterAgainCharacter* MyCharacter;
	 //try new functions
	 int AtakAnim(float AtakTime);
	 int PrevAttackTick;
	 float AttackAnimTime = 0.0f;
		
	 //раздел медведа, опасная зона
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		 float CameraSpeed;
	 UPROPERTY(EditAnywhere,BlueprintReadWrite)
		 float CameraUp;
	 UPROPERTY(EditAnywhere,BlueprintReadWrite)
		 float CameraDown;

	 float ZoomFactor;
	 int bZooming;

	 void ZoomIn();
	 void ZoomOut();
	/** Input handlers for SetDestination action. */
	
};


