// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectTFG_U_v1/AI/EnemyAIController.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"

AEnemyAIController::AEnemyAIController()
{
	Perception=CreateDefaultSubobject<UAIPerceptionComponent>(FName("PerceptionComponent"));

	//Add view perception
	Sight=CreateDefaultSubobject<UAISenseConfig_Sight>(FName("Sight"));
	Sight->DetectionByAffiliation.bDetectEnemies=true;
	Sight->DetectionByAffiliation.bDetectFriendlies=true;
	Sight->DetectionByAffiliation.bDetectNeutrals=true;

	Sight->PeripheralVisionAngleDegrees=120.0f;
	Sight->SightRadius=1500.0f;
	Sight->LoseSightRadius=1650.0f;


	Perception->ConfigureSense(*Sight);
}

void AEnemyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if(!Behavior) return;
	RunBehaviorTree(Behavior);
	
}

void AEnemyAIController::BeginPlay()
{
	Super::BeginPlay();

	if(!Perception) return;

	Perception->OnTargetPerceptionUpdated.AddDynamic(this, &AEnemyAIController::OnSlayerPercepction);
}

void AEnemyAIController::OnSlayerPercepction(AActor* Actor, FAIStimulus Stimulus)
{
	if(!GetBlackboardComponent()) return;
	if(Actor->ActorHasTag(FName("Hero")))
	{
		if(Stimulus.WasSuccessfullySensed())
		{
			GetBlackboardComponent()->SetValueAsObject(FName("CharachterM"), Actor);
		}
		/*else
		{
			GetBlackboardComponent()->ClearValue(FName("CharachterM"));
		}*/
	}
	

	
	
}
