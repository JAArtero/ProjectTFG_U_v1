// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MyPlayerMAnimInstance.generated.h"


UCLASS()
class PROJECTTFG_U_V1_API UMyPlayerMAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	virtual void  NativeInitializeAnimation() override;

private:
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category=Movement, meta=(AllowPrivateAccess="true"))
	class AMyCharacterM* PlayerCharacterM;
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
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category=Movement, meta=(AllowPrivateAccess="true"))
	int Weapon_Selected;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category=Movement, meta=(AllowPrivateAccess="true"))
	bool bIsTumble;
protected:

	
};
