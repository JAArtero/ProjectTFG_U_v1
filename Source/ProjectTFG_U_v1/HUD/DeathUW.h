// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DeathUW.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTTFG_U_V1_API UDeathUW : public UUserWidget
{
	GENERATED_BODY()

public:

	void RebootGame();

	void EndCurrentGame();

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* Button_Reboot;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* Button_Quit;


	
};
