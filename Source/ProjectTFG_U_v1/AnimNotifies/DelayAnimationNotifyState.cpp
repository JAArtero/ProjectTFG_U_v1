// Fill out your copyright notice in the Description page of Project Settings.


#include "DelayAnimationNotifyState.h"

#include "GameFramework/CharacterMovementComponent.h"

void UDelayAnimationNotifyState::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration,
                                             const FAnimNotifyEventReference& EventReference)
{
	//GEngine->AddOnScreenDebugMessage(-1,5.f,FColor::Green, TEXT("Notify Begin"));
	
	
}

void UDelayAnimationNotifyState::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
	const FAnimNotifyEventReference& EventReference)
{
	//GEngine->AddOnScreenDebugMessage(-1,5.f,FColor::Green, TEXT("Notify End"));

	

}