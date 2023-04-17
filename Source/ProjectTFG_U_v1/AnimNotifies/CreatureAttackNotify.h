// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "CreatureAttackNotify.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTTFG_U_V1_API UCreatureAttackNotify : public UAnimNotify
{
	GENERATED_BODY()
	void  Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;

private:
	UPROPERTY(EditAnywhere, Category= Params)
	FName HandSocket{};
	
	UPROPERTY(EditAnywhere, Category= Params)
	float Damage{20.0f};

	UPROPERTY(EditAnywhere, Category= Params)
	float PunchRadius {35.0f};

	UPROPERTY(EditAnywhere, Category= Params)
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	
};
