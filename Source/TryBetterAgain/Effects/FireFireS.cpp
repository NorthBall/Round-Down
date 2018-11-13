#include "FireFireS.h"
#include "CommonAncestor.h"
UFireFireS::UFireFireS()
{
	BuffCount = 0;
	EffectTime = 5.0f;
	IsPermanent = false;
	IsPositive = true;
	Dispellable = true;
	Name = ENameEffects::FireFireS;
}

void UFireFireS::Apply(float Delta)
{
	Target->RealA["AttackSpeed"] += BuffCount * 10;
	Target->RealM["CastTime"] /= (1.0f + 0.05*BuffCount);
	Target->RealM["CoolDownTime"] /= 1.0 + 0.04 * BuffCount;
	EffectTime -= Delta;
	//UE_LOG(LogTemp, Warning, TEXT("EffectTime=%f"), EffectTime);
}
void UFireFireS::IncrementEffect(int32 i)
{
	BuffCount = (Target->SkillLevel[(int32)ESkill::FireFire - (int32)ESkill::Fire_Start] > BuffCount + i) ? BuffCount + i : Target->SkillLevel[(int32)ESkill::FireFire - (int32)ESkill::Fire_Start];
	EffectTime = 5.0f;
	
	if (Model == nullptr)
	{
		Model = Target->GetWorld()->SpawnActor<AActor>(VRepr, FVector(0.0f), FRotator::ZeroRotator);
		if (Model != nullptr)
			Model->AttachToComponent(Target->GetMesh(), FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), FName(TEXT("Hand_L")));	
	}
	if (ModelR == nullptr)
	{
		ModelR = Target->GetWorld()->SpawnActor<AActor>(VRepr, FVector(0.0f), FRotator::ZeroRotator);
		if (ModelR != nullptr)
			ModelR->AttachToComponent(Target->GetMesh(), FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), FName(TEXT("Hand_R_001")));
	}
	if (Model != nullptr && ModelR!=nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("%d this scale %f"), BuffCount, BuffCount / 5.0f);
		Model->SetActorRelativeScale3D(FVector(BuffCount / 5.0f));
		ModelR->SetActorRelativeScale3D(FVector(BuffCount / 5.0f));
	}
	//UE_LOG(LogTemp, Warning, TEXT("%d this scale %f"), BuffCount, BuffCount / 5.0f);
}
void UFireFireS::DeleteSelf()
{
	if (Model->IsValidLowLevel())
	{
		Model->Destroy();
		Model = nullptr;
	}
	if (ModelR->IsValidLowLevel())
	{
		ModelR->Destroy();
		ModelR = nullptr;
	}
}