// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectTFG_U_v1/AnimNotifies/SwordAnimNotifyState.h"

#include "ProjectTFG_U_v1/MyCharacterM.h"

void USwordAnimNotifyState::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
                                        float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	//Super::NotifyBegin(MeshComp, Animation, TotalDuration, EventReference);

	if(MeshComp && MeshComp->GetOwner())
	{
		MyCharacter=Cast<AMyCharacterM>(MeshComp->GetOwner());
		if(MyCharacter)
		{
			MyCharacter->ActivateSwordBoxCollision();
		}
	}
}

void USwordAnimNotifyState::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
	const FAnimNotifyEventReference& EventReference)
{
	//Super::NotifyEnd(MeshComp, Animation, EventReference);
	MyCharacter=Cast<AMyCharacterM>(MeshComp->GetOwner());
	if(MyCharacter)
	{
		MyCharacter->DeactivateSwordBoxCollision();
	}
}
