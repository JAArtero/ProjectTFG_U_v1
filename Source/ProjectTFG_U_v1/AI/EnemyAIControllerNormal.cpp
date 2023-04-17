// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectTFG_U_v1/AI/EnemyAIControllerNormal.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"

AEnemyAIControllerNormal::AEnemyAIControllerNormal()
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

void AEnemyAIControllerNormal::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	if(!Behavior) return;
	RunBehaviorTree(Behavior);
}

void AEnemyAIControllerNormal::BeginPlay()
{
	Super::BeginPlay();

	if(!Perception) return;
	Perception->OnTargetPerceptionUpdated.AddDynamic(this, &AEnemyAIControllerNormal::OnSlayerPercepction);
}

void AEnemyAIControllerNormal::OnSlayerPercepction(AActor* Actor, FAIStimulus Stimulus)
{
	if(!GetBlackboardComponent()) return;
	if(Actor->ActorHasTag(FName("Hero")))
	{
		//Stimulus detection
		if(Stimulus.WasSuccessfullySensed())
		{
			GetBlackboardComponent()->SetValueAsObject(FName("PlayerHero"), Actor);
		}
		else
		{
			GetBlackboardComponent()->ClearValue(FName("PlayerHero"));
		}
	}
}
