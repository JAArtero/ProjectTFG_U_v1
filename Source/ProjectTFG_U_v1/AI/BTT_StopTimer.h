// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTT_StopTimer.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTTFG_U_V1_API UBTT_StopTimer : public UBTTaskNode
{
	GENERATED_BODY()
	
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

public:
	UPROPERTY(EditAnywhere, Category="Type of Attack")
	bool InAttack {false};
};
