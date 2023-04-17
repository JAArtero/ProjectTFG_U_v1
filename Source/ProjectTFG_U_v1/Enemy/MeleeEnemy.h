// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectTFG_U_v1/Enemy/Enemy.h"
#include "MeleeEnemy.generated.h"


UCLASS()
class PROJECTTFG_U_V1_API AMeleeEnemy : public AEnemy
{
	GENERATED_BODY()

private:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Atack_Animation, meta=(AllowPrivateAccess="true"))
	float BaseApplyDamage;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attack_Animation, meta=(AllowPrivateAccess="true"))
	UAnimMontage* Attack_Enemy_Montage {nullptr};
		
	
public:
	void MeleeAttack();
	
};
