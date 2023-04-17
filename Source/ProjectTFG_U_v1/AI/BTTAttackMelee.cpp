// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectTFG_U_v1/AI/BTTAttackMelee.h"

#include "AIController.h"
#include "ProjectTFG_U_v1/Enemy/MeleeEnemy.h"

EBTNodeResult::Type UBTTAttackMelee::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto AC=OwnerComp.GetAIOwner();
	if(!AC) return EBTNodeResult::Failed;
	
	auto pawn=Cast<AMeleeEnemy>(AC->GetPawn());

	if(!pawn) return EBTNodeResult::Failed;
	InAttack=true;
	pawn->MeleeAttack();
	

	return EBTNodeResult::Succeeded;
}