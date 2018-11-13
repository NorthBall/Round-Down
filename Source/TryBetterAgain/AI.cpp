// Fill out your copyright notice in the Description page of Project Settings.

#include "AI.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "TryBetterAgainCharacter.h"

// Sets default values
AAI::AAI():ACommonAncestor()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.


}
/*
// Called when the game starts or when spawned
void AAI::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAI::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

*/


void AAI::AttackInRange(ACommonAncestor * Player, float Delta)
{
	if (AttackAnimTime < 0)
	{
		AttackAnimTime += Delta / AttackTime;
	}
	else
	{
		FRotator deltaRotate = (Player->GetActorLocation() - GetActorLocation()).Rotation();
		deltaRotate.Pitch = 0;
		SetActorRotation(deltaRotate);
		OnePunch = true;
		AttackAnimTime += Delta / AttackTime;
		if (PrevAttackTick != 2)
		{
			PrevAttackTick = AttackAnim(AttackAnimTime);
			if (PrevAttackTick == 2 || PrevAttackTick == 3)
			{
				DoAttack(Player);
			}
		}
		else
		{
			PrevAttackTick = AttackAnim(AttackAnimTime);
		}
		if (PrevAttackTick == 3)
		{
			PrevAttackTick = 1;
			AttackAnimTime -= 1.0f;
		}
	}
	
}
void AAI::AbortingAttack()
{
	OnePunch = false;
	AttackAnimTime = 0.0f;
}

int32 AAI::AttackAnim(float Time)
{
	if (Time < PreAttack) return 1;
	if (Time < 1.0f) return 2;
	return 3;
}

void AAI::Dead()
{
	UE_LOG(LogTemp, Warning, TEXT("Why"));
	ATryBetterAgainCharacter* Player;
	TArray<AActor*> Aplayer;
	TSubclassOf<ATryBetterAgainCharacter> ClassToFind;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATryBetterAgainCharacter::StaticClass(), Aplayer);
	if (Aplayer.Num() > 0)
	{
		if (Aplayer[0]->IsValidLowLevel())
		{
			Player = Cast<ATryBetterAgainCharacter> (Aplayer[0]);
			if (Player != nullptr)
			{
				Player->Exp += ExpBounty;
				UE_LOG(LogTemp, Warning, TEXT("Exp=%d"), Player->Exp);
				Player->UpdateExp();
			}
		}
	}
	Destroy();
}
