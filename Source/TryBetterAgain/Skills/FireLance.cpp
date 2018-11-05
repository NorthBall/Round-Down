// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "FireLance.h"
#include "Effects.h"
#include "Effects/FireBurnE.h"
#include "Components/SphereComponent.h"
#include "Runtime/Engine/Classes/Particles/ParticleSystemComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "TryBetterAgainCharacter.h"

AFireLance::AFireLance():AMotherOfProjectiles()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
	CollisionComp->OnComponentHit.AddDynamic(this, &AFireLance::OnHit);
}
void AFireLance::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (Exploding)
	{
		TimeToDissapear -= DeltaSeconds;
		//UE_LOG(LogTemp, Warning, TEXT("Tryin %f"), TimeToDissapear);
		if (TimeToDissapear<0.0f)
		{
			Destroy();
		}
	}
}
void AFireLance::BeginPlay()
{
	Super::BeginPlay();
	


}
void AFireLance::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("HitSomething"));
	// Only add impulse and destroy projectile if we hit a physics
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		AAI* victim = Cast<AAI>(OtherActor);
		ATryBetterAgainCharacter* Hero = Cast<ATryBetterAgainCharacter>(owner);
		if (Hero == nullptr)
		{
			Destroy();
			return;
		}
		if (victim == nullptr) {
			return;
		}
		int32 Damage = (100 * Hero->SkillLevel[(int32)Skill::FireLance - (int32)Skill::Fire_Start] + Hero->RealA["MagicPower"])*Hero->RealM["MagicPower"]*victim->RealM["MagicMultiplier"];
		victim->Health -= Damage;
		Hero->FireAfterBurn(victim, Damage);
		Hero->FireBurn(victim);
		int32 i, n;
		AAI* Target;
		UEffects* SpellEffect;
		UEffects* BurnEffect;

		float Range= (150 + Hero->RealA["MagicRange"])*Hero->RealM["MagicRange"];
		TArray<FOverlapResult> All;
		GetWorld()->OverlapMultiByObjectType(All, victim->GetActorLocation()+GetActorRotation().Vector()*75, FQuat(), ECollisionChannel::ECC_Pawn, FCollisionShape::MakeSphere(Range));
		n = All.Num();
		UE_LOG(LogTemp, Warning, TEXT("SpellCasted range= %f, actors= %d"), Range, n);
		for (i = 0; i < n; i++)
		{
			Target = Cast<AAI>(All[i].GetActor());
			if (Target != nullptr)
			{
				Damage = (50 * Hero->SkillLevel[(int32)Skill::FireLance - (int32)Skill::Fire_Start] + Hero->RealA["MagicPower"])*Hero->RealM["MagicPower"]*Target->RealM["MagicMultiplier"];
				Target->Health -= Damage;
				SpellEffect = Hero->FireAfterBurn(Target, Damage);
				BurnEffect = Hero->FireBurn(Target);
				if (Target->Health <= 0) Target->Dead();
			}
		}
		Hero->UpdateAll();
		Changes();
		
	}
}

void AFireLance::Changes()
{
	UE_LOG(LogTemp, Warning, TEXT("Tryin to Stop"));
	LanceSelf->SetVisibility(false);
	Explosion->SetVisibility(true);
	Exploding = true;
	ProjectileMovement->Velocity = FVector(0);
	CollisionComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}



