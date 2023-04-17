// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "ProjectTFG_U_v1/Enemy/MeleeEnemy.h"

#include "BTTAttackMelee.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTTFG_U_V1_API UBTTAttackMelee : public UBTTaskNode
{
	GENERATED_BODY()

	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

public:
	
	UPROPERTY(EditAnywhere, Category="Type of Attack")
	bool InAttack {false};
	
	
};
