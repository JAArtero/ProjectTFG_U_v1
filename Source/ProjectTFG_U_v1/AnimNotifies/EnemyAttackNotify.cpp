// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectTFG_U_v1/AnimNotifies/EnemyAttackNotify.h"

//#include "ProjectTFG_U_v1/Enemy/Enemy.h"
#include "ProjectTFG_U_v1/Enemy/FinalBoss.h"

void UEnemyAttackNotify::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
                                     float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	//Super::NotifyBegin(MeshComp, Animation, TotalDuration, EventReference);
	if(MeshComp && MeshComp->GetOwner())
	{
		EnemyCharacter=Cast<AFinalBoss>(MeshComp->GetOwner());
		if(EnemyCharacter)
		{
			EnemyCharacter->ActivateArmBoxCollision();
		}
	}
	
}

void UEnemyAttackNotify::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
	const FAnimNotifyEventReference& EventReference)
{
	//Super::NotifyEnd(MeshComp, Animation, EventReference);

	EnemyCharacter=Cast<AFinalBoss>(MeshComp->GetOwner());
	if(EnemyCharacter)
	{
		EnemyCharacter->DeactivateArmBoxCollision();
	}
	
}
