// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionTypes.h"

#include "EnemyAIControllerNormal.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTTFG_U_V1_API AEnemyAIControllerNormal : public AAIController
{
	GENERATED_BODY()

public:
	
	AEnemyAIControllerNormal();
	
	//Add decision tree
	void OnPossess(APawn* InPawn) override;

	
protected:
	void BeginPlay() override;

protected:
	UPROPERTY(VisibleAnywhere, Category="Component")
	class UAIPerceptionComponent* Perception {nullptr};


	//Add Sense
	class UAISenseConfig_Sight* Sight {nullptr};

	UPROPERTY(EditDefaultsOnly, Category="AI")
	UBehaviorTree* Behavior {nullptr};
	
private:
	UFUNCTION()
	void OnSlayerPercepction(AActor* Actor, FAIStimulus Stimulus);
	
};
