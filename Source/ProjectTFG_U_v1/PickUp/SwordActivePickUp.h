// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectTFG_U_v1/PickUp/PickUpBase.h"
#include "SwordActivePickUp.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTTFG_U_V1_API ASwordActivePickUp : public APickUpBase
{
	GENERATED_BODY()

public:

	bool ActivatePickUp() override;

protected:
	UPROPERTY(EditDefaultsOnly, Category=Stats)
	bool SwordActive {true};
	
};
