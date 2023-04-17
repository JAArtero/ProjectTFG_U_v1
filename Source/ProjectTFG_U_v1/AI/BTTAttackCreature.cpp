// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectTFG_U_v1/AI/BTTAttackCreature.h"

#include "AIController.h"
#include "ProjectTFG_U_v1/Enemy/FromDistanceEnemy.h"

EBTNodeResult::Type UBTTAttackCreature::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto AC=OwnerComp.GetAIOwner();
	if(!AC) return EBTNodeResult::Failed;
	
	auto pawn=Cast<AFromDistanceEnemy>(AC->GetPawn());
	if(!pawn) return EBTNodeResult::Failed;

	InAttack=true;
	pawn->Attack(AttackType);

	return EBTNodeResult::Succeeded;

	
}
