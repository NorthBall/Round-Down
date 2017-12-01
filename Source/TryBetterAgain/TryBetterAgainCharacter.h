// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.


#include "CoreMinimal.h"
#include "CommonAncestor.h"
#include "GameFramework/Character.h"
#include "AI.h"
#include "TryBetterAgainCharacter.generated.h"

UCLASS(Blueprintable)
class ATryBetterAgainCharacter : public ACommonAncestor
{
	GENERATED_BODY()

public:
	//class definitons
	UPROPERTY( BlueprintReadWrite, Category = "Class")
		int32 MyClass;

	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<class AFireLance> LanceBP;//копье

	//UFUNCTION(BlueprintCallable, Category = "Attack")
		void DoAttack(ACommonAncestor *Victim) ;
	//playable functions
	UFUNCTION(BlueprintCallable, Category = "Class")
		void ChooseClass(int32 choise)	{};
	//class functions MAY BE VERY MUCH
	class Effects* FireBurn(ACommonAncestor *Victim);
	Effects* FireFire(int32 i=1);
	Effects* FireAfterBurn(ACommonAncestor *Victim, int32 Damage);
	void FireBlink(FHitResult Hit);
	void FireLance(FHitResult Hit);




	ATryBetterAgainCharacter();

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	bool FacedToEnemy(FVector enemyLocation);

	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	//FORCEINLINE class USceneComponent* GetRoot() const { return RootComponent; }
	/** Returns CursorToWorld subobject **/
	FORCEINLINE class UDecalComponent* GetCursorToWorld() { return CursorToWorld; }
//	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
//		class UNavMovementComponent* Dumb;

	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** A decal that projects to the cursor location. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UDecalComponent* CursorToWorld;

	UPROPERTY(EditAnywhere)
		float CameraSpeed;
	UPROPERTY(EditAnywhere)
		float CameraUp;
	UPROPERTY(EditAnywhere)
		float CameraDown;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class ATryBetterAgainPlayerController* RealController;
	float ZoomFactor;
	int bZooming;

	void ZoomIn();
	void ZoomOut();
	//void NoZoom();

};

