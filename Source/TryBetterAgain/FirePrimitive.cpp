// Fill out your copyright notice in the Description page of Project Settings.

#include "FirePrimitive.h"
#include "Effects.h"
#include "Components/SphereComponent.h"
#include "TryBetterAgainCharacter.h"

AFirePrimitive::AFirePrimitive() :AMotherOfProjectiles()
{

	CollisionComp->OnComponentHit.AddDynamic(this, &AFirePrimitive::OnHit);
}
void AFirePrimitive::BeginPlay()
{
	Super::BeginPlay();



}
void AFirePrimitive::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("HitSomething"));
	// Only add impulse and destroy projectile if we hit a physics
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		AAI* victim = Cast<AAI>(OtherActor);
		if (victim == nullptr) {
			return;
		}
		ATryBetterAgainCharacter* Hero = Cast<ATryBetterAgainCharacter>(owner);
		if (Hero == nullptr)
		{
			Destroy();
			return;
		}
		
		int32 Damage = (50 * Hero->SkillLevel[(int32)Skill::FireQueue - (int32)Skill::Fire_Start] + Hero->MagicPowerA)*Hero->MagicPowerM*victim->MagicMultiplierM;
		victim->Health -= Damage;
		Hero->FireAfterBurn(victim, Damage);
		Hero->FireBurn(victim);

		Hero->UpdateAll();
		Destroy();
	}
}



