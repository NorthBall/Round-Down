// Fill out your copyright notice in the Description page of Project Settings.
#pragma  once
#include "MyFireAura.h"
#include "Components/SphereComponent.h"
#include "TryBetterAgainCharacter.h"
#include "AI.h"
#include "Effects.h"


// Sets default values
AMyFireAura::AMyFireAura()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Aura = CreateDefaultSubobject<USphereComponent>(TEXT("Aura"));
	Aura->OnComponentBeginOverlap.AddDynamic(this, &AMyFireAura::FireAuraPlay);
	Aura->OnComponentEndOverlap.AddDynamic(this, &AMyFireAura::FireAuraDontPlay);
	Aura->SetCollisionResponseToAllChannels(ECR_Overlap);
	Owner = nullptr;
	Duration = 25.0f;
	RootComponent = Aura;
	Aura->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}

// Called when the game starts or when spawned
void AMyFireAura::BeginPlay()
{
	Super::BeginPlay();
	Aura->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	
}

// Called every frame
void AMyFireAura::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	UE_LOG(LogTemp, Warning, TEXT("time %f,radius=%f"), Duration,Aura->GetUnscaledSphereRadius());
	Duration -= DeltaTime;
	if (Duration <= 0.0f)
	{
		if (Owner != nullptr)
		{
			Owner->DeleteEffect(Owner->FireEffectAura);
			Owner->FireEffectAura = nullptr;
		}
		Destroy();
	}
	

}

void AMyFireAura::FireAuraPlay(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//UE_LOG(LogTemp, Warning, TEXT("Prooobleeems"));
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) &&(OtherActor!=Owner))
	{
		UE_LOG(LogTemp, Warning, TEXT("FireAuraAttacks"));
		AAI *victim = Cast<AAI>(OtherActor);
		if (victim == nullptr) return;
		UE_LOG(LogTemp, Warning, TEXT("CastToVictim"));
		Effects *AddEffect = victim->AddNewEffect(false, true, false, NameEffects::FireAuraE);
		if (AddEffect == nullptr) return;
		AddEffect->IsSingle = false;
		AddEffect->TickMHealthA = -10;
		AddEffect->MagicMultiplierM = 2.0f;
		victim->CalcOneEffect(AddEffect, 0.0f);
	}
}
void AMyFireAura::FireAuraDontPlay(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		AAI *victim = Cast<AAI>(OtherActor);
		if (victim == nullptr) return;
		Effects *DeletingEffect = victim->FindName(NameEffects::FireAuraE);
		if (DeletingEffect == nullptr) return;
		victim->DeleteEffect(DeletingEffect);

	}
}