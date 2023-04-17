// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectTFG_U_v1/HUD/PauseMenuUW.h"
#include "GameFramework/PlayerController.h"


#include "Kismet/GameplayStatics.h"



void UPauseMenuUW::ReanudeGame()
{
	APlayerController* FPC=GetWorld()->GetFirstPlayerController();   //<APlayerController>();
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red,FString::Printf(TEXT("Reanudar")));
     
	//UGameplayStatics::SetGamePaused(GetWorld(),false);
	FPC->SetPause(false);
}

void UPauseMenuUW::EndCurrentGame()
{

	
}
