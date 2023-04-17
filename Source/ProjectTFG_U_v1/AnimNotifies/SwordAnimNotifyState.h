// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "SwordAnimNotifyState.generated.h"

class AMyCharacterM;

UCLASS()
class PROJECTTFG_U_V1_API USwordAnimNotifyState : public UAnimNotifyState
{
	GENERATED_BODY()

public:

	UPROPERTY()
	AMyCharacterM* MyCharacter;

	//Functions declared
	virtual void NotifyBegin(USkeletalMeshComponent * MeshComp, UAnimSequenceBase * Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference) override;
	virtual void NotifyEnd(USkeletalMeshComponent * MeshComp, UAnimSequenceBase * Animation, const FAnimNotifyEventReference& EventReference) override;
	
};
