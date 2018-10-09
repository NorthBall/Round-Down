// Fill out your copyright notice in the Description page of Project Settings.

#include "FireMeteor.h"
#include "TryBetterAgainCharacter.h"
#include "Effects.h"


// Sets default values
AFireMeteor::AFireMeteor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("DummyRoot"));
	RootComponent = Root;
}

// Called when the game starts or when spawned
void AFireMeteor::BeginPlay()
{
	Super::BeginPlay();
	TimeToRelease = 2.0f;
	
}

// Called every frame
void AFireMeteor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TimeToRelease -= DeltaTime;
	if (TimeToRelease < 0)
	{
		if (Hero == nullptr)
		{
			Destroy();
			return;
		}
		int32 Damage;
		int32 i, n;
		AAI* Target;
		Effects* OursEffect;
		Effects* BurnEffect;
		float Range = (150 + Hero->RealA["MagicRange"])*Hero->RealM["MagicRange"];
		TArray<FOverlapResult> All;
		GetWorld()->OverlapMultiByObjectType(All, GetActorLocation(), FQuat(), ECollisionChannel::ECC_Pawn, FCollisionShape::MakeSphere(Range));
		n = All.Num();
		UE_LOG(LogTemp, Warning, TEXT("SpellCasted range= %f, actors= %d"), Range, n);
		UE_LOG(LogTemp, Warning, TEXT("x= %f, y=%f,z=%f"), GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z);
		for (i = 0; i < n; i++)
		{
			Target = Cast<AAI>(All[i].GetActor());
			if (Target != nullptr)
			{

				Damage = (100 * Hero->SkillLevel[(int32)Skill::FireMeteor - (int32)Skill::Fire_Start] + Hero->RealA["MagicPower"])*Hero->RealM["MagicPower"]*Target->RealM["MagicMultiplier"];
				UE_LOG(LogTemp, Warning, TEXT("Level=%d,Power=%f,Armor=%f"), Hero->SkillLevel[(int32)Skill::FireMeteor - (int32)Skill::Fire_Start], Hero->RealM["MagicPower"], Target->RealM["MagicMultiplier"]);
				Target->Health -= Damage;
				OursEffect = Hero->FireAfterBurn(Target, Damage);
				BurnEffect = Hero->FireBurn(Target);
				if (Target->Health <= 0) Target->Dead();
			}
		}
		Destroy();
	}
}

