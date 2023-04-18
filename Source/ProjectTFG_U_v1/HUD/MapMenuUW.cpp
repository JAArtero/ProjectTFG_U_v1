// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectTFG_U_v1/HUD/MapMenuUW.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"


void UMapMenuUW::ReanudeGame()
{
	APlayerController* FPC=GetWorld()->GetFirstPlayerController();   
	     
	//UGameplayStatics::SetGamePaused(GetWorld(),false);
	FPC->SetPause(false);
}
