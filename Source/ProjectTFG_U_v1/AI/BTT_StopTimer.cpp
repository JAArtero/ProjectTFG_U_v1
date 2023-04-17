// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectTFG_U_v1/AI/BTT_StopTimer.h"
#include "AIController.h"
#include "ProjectTFG_U_v1/Enemy/FinalBoss.h"

EBTNodeResult::Type UBTT_StopTimer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto AC=OwnerComp.GetAIOwner();
	if(!AC) return EBTNodeResult::Failed;
	
	auto pawn=Cast<AFinalBoss>(AC->GetPawn());

	if(!pawn) return EBTNodeResult::Failed;
	InAttack=true;
	pawn->ClearTimer();
	

	return EBTNodeResult::Succeeded;
}