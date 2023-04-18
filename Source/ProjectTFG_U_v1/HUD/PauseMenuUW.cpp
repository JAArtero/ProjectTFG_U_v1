// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectTFG_U_v1/HUD/PauseMenuUW.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"



void UPauseMenuUW::ReanudeGame()
{
	APlayerController* FPC=GetWorld()->GetFirstPlayerController(); 
    FPC->SetPause(false);
}

void UPauseMenuUW::EndCurrentGame()
{

	
}
