// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectTFG_U_v1/AI/DistanceService.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

void UDistanceService::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	if (!OwnerComp.GetAIOwner()) return;

	//Recover pawn
	auto pawn=OwnerComp.GetAIOwner()->GetPawn();
	if(!pawn) return;

	//Recover player
	auto bb=OwnerComp.GetBlackboardComponent();
	if(!bb) return;
	auto MyCharacterPlayer=Cast<AActor>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(MyCharacterKey.SelectedKeyName));
	if(!MyCharacterPlayer) return;

	//Calculate distance of two objects
	auto distance=pawn->GetDistanceTo(MyCharacterPlayer);
	auto cd=distance<=MinDistanceToAttack;
	if(cd)
	{
		bb->SetValueAsBool(CheckDistanceKey.SelectedKeyName,true);
		return;
	}
	bb->SetValueAsBool(CheckDistanceKey.SelectedKeyName,false);

}
