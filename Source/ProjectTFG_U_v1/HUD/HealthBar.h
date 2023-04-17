// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HealthBar.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTTFG_U_V1_API UHealthBar : public UUserWidget
{
	GENERATED_BODY()


public:
	/** Update HUD with current health. */
	void SetHealth(float CurrentHealth, float MaxHealth);

	//Health Section
	/** Widget to use to display current health. */
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UProgressBar* Live_Bar_Progresion;
};

