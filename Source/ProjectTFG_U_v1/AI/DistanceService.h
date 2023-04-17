// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "DistanceService.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTTFG_U_V1_API UDistanceService : public UBTService
{
	GENERATED_BODY()

protected:
	void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

public:
	
	UPROPERTY(EditAnywhere, Category="BBKeys")
	FBlackboardKeySelector MyCharacterKey;

	UPROPERTY(EditAnywhere, Category="BBKeys")
	FBlackboardKeySelector CheckDistanceKey;

	UPROPERTY(EditAnywhere, Category="Params")
	float MinDistanceToAttack{200.0f};

	
};
