// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MyPlayerAAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTTFG_U_V1_API UMyPlayerAAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	//void UpdateAnimationProperty(float Deltatime);
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	virtual void  NativeInitializeAnimation() override;

private:
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category=Movement, meta=(AllowPrivateAccess="true"))
	class AMyCharacterA* PlayerCharacterA;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category=Movement, meta=(AllowPrivateAccess="true"))
	float Speed;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category=Movement, meta=(AllowPrivateAccess="true"))
	bool bIsInAir;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category=Movement, meta=(AllowPrivateAccess="true"))
	bool bIsAccelerating;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category=Movement, meta=(AllowPrivateAccess="true"))
	float MovementOffsetYaw;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category=Movement, meta=(AllowPrivateAccess="true"))
	float LastMovementOffsetYaw;
	
};
