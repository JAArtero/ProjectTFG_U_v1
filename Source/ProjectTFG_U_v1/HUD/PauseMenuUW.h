// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Widgets/Input/SButton.h"


#include "PauseMenuUW.generated.h"


/**
 * 
 */
UCLASS()
class PROJECTTFG_U_V1_API UPauseMenuUW : public UUserWidget
{
	GENERATED_BODY()

public:

	void ReanudeGame();

	void EndCurrentGame();

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* Button_Continue;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* Button_Quit;
};
