// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "ProjectTFG_U_v1/Enemy/FinalBoss.h"
#include "EnemyAttackNotify.generated.h"


class AFinalBoss;

UCLASS()
class PROJECTTFG_U_V1_API UEnemyAttackNotify : public UAnimNotifyState
{
	GENERATED_BODY()

public:
	UPROPERTY()
	AFinalBoss* EnemyCharacter;
	
	//Functions declared
	virtual void NotifyBegin(USkeletalMeshComponent * MeshComp, UAnimSequenceBase * Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference) override;
	virtual void NotifyEnd(USkeletalMeshComponent * MeshComp, UAnimSequenceBase * Animation, const FAnimNotifyEventReference& EventReference) override;
};
