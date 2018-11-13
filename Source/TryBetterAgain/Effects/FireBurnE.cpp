#include "FireBurnE.h"
#include "CommonAncestor.h"
#include "Components/CapsuleComponent.h"

void UFireBurnE::DeleteSelf()
{
	UE_LOG(LogTemp, Warning, TEXT("DeleteActor"));
	if (Model->IsValidLowLevel())
	{
		Model->Destroy();
		Model = nullptr;
	}
}

UFireBurnE::UFireBurnE()
{
	DebuffCount = 1;
	EffectTime = 5.0f;
	IsPermanent = false;
	IsPositive = false;
	Dispellable = true;
	Name = ENameEffects::FireBurnE;
}
UFireBurnE::~UFireBurnE()
{
	//UE_LOG(LogTemp, Warning, TEXT("deleting Effect"));
}
void UFireBurnE::IncrementEffect(int32 i)
{
	DebuffCount = (Caster->SkillLevel[(int32)ESkill::FireBurn - (int32)ESkill::Fire_Start] > DebuffCount + i) ? DebuffCount + i : Caster->SkillLevel[(int32)ESkill::FireBurn - (int32)ESkill::Fire_Start];
	if (Model == nullptr)
	{
		Model = Target->GetWorld()->SpawnActor<AActor>(VRepr, FVector(0.0f), FRotator::ZeroRotator);
		if (Model != nullptr)
		{
			Model->AttachToActor(Target, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true));
			Model->SetActorRelativeScale3D(FVector(Target->GetCapsuleComponent()->GetScaledCapsuleRadius())/100.0f);
		}
	}
	EffectTime = 5.0f;
}
void UFireBurnE::Apply(float Delta)
{
	TimeSum += Delta;
	if (TimeSum >= 0.25f)
	{
		Target->RealA["TickDamage"] += DebuffCount;
		UE_LOG(LogTemp, Warning, TEXT("Let's go %d, ,%d"), Target->RealA["TickDamage"], DebuffCount);
		TimeSum -= 0.25;
	}
	EffectTime -= Delta;
	UE_LOG(LogTemp, Warning, TEXT("EffectTime=%f"), EffectTime);
}