//************************************************************************************
//**************************** Create Task To Tree ***********************************
//***********************************************************************************

#include "ProjectTFG_U_v1/AI/AttackTask.h"

#include "AIController.h"
#include "ProjectTFG_U_v1/Enemy/FinalBoss.h"

EBTNodeResult::Type UAttackTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto AC=OwnerComp.GetAIOwner();
	if(!AC) return EBTNodeResult::Failed;
	
	auto pawn=Cast<AFinalBoss>(AC->GetPawn());

	if(!pawn) return EBTNodeResult::Failed;
	InAttack=true;
	pawn->Attack(AttackType);
	

	return EBTNodeResult::Succeeded;
}
