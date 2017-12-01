// Fill out your copyright notice in the Description page of Project Settings.

#include "FireLance.h"
#include "Effects.h"
#include "Components/SphereComponent.h"
#include "TryBetterAgainCharacter.h"

AFireLance::AFireLance():AMotherOfProjectiles()
{

	CollisionComp->OnComponentHit.AddDynamic(this, &AFireLance::OnHit);
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
		int32 Damage = (100 * Hero->SkillLevel[(int32)Skill::FireLance - (int32)Skill::Fire_Start] + Hero->MagicPowerA)*Hero->MagicPowerM;
		victim->Health -= Damage;
		Hero->FireAfterBurn(victim, Damage);
		Hero->FireBurn(victim);
		int32 i, n;
		AAI* Target;
		Effects* OursEffect;
		Effects* BurnEffect;

		float Range= (150 + Hero->MagicRangeA)*Hero->MagicRangeM;
		TArray<FOverlapResult> All;
		GetWorld()->OverlapMultiByObjectType(All, victim->GetActorLocation()+GetActorRotation().Vector()*75, FQuat(), ECollisionChannel::ECC_Pawn, FCollisionShape::MakeSphere(Range));
		n = All.Num();
		UE_LOG(LogTemp, Warning, TEXT("SpellCasted range= %f, actors= %d"), Range, n);
		for (i = 0; i < n; i++)
		{
			Target = Cast<AAI>(All[i].GetActor());
			if (Target != NULL)
			{

				Damage = (50 * Hero->SkillLevel[(int32)Skill::FireBlink - (int32)Skill::Fire_Start] + Hero->MagicPowerA)*Hero->MagicPowerM;
				Target->Health -= Damage;
				OursEffect = Hero->FireAfterBurn(Target, Damage);
				BurnEffect = Hero->FireBurn(Target);
				if (Target->Health <= 0) Target->Dead();
			}
		}
		Hero->UpdateAll();
		Destroy();

	}
}



