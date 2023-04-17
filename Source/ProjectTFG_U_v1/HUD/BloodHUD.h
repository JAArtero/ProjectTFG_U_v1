// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "BloodHUD.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTTFG_U_V1_API ABloodHUD : public AHUD
{
	GENERATED_BODY()

	UTexture2D* Blood;
	
	ABloodHUD();
	virtual void DrawHUD();

};
