// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MapMenuUW.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTTFG_U_V1_API UMapMenuUW : public UUserWidget
{
	GENERATED_BODY()
public:

	void ReanudeGame();

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* Button_Continue;
	
};
