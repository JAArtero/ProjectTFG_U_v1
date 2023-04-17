// Copyright Epic Games, Inc. All Rights Reserved.


#include "ProjectTFG_U_v1GameModeBase.h"

#include "ProjectTFG_U_v1/HUD/GameHUD.h"
#include "ProjectTFG_U_v1/Components/ImpactFX.h"
#include "ProjectTFG_U_v1/HUD/MyHUDWidget.h"
#include "Kismet/GameplayStatics.h"



AProjectTFG_U_v1GameModeBase::AProjectTFG_U_v1GameModeBase()
{
	//character used to play
	static ConstructorHelpers::FClassFinder<APawn>  PlayerCharacterBP(TEXT("/Game/ThirdPerson/Blueprints/BP_MyCharacterM"));    
	
	if(PlayerCharacterBP.Class !=NULL)
	{
		DefaultPawnClass=PlayerCharacterBP.Class;
		
	}
	//Add HUD
	//HUDClass=UGameHUD::StaticClass();
	//HUDClass=UMyHUDWidget::StaticClass();
	
}


//Create Timer to restart game 
void AProjectTFG_U_v1GameModeBase::RestartGameTimer()
{
	FTimerDynamicDelegate restartDelegate{};
	restartDelegate.BindUFunction(this, FName("OnRestartGame"));
	GetWorldTimerManager().SetTimer(RestartGame_TimerHandle, restartDelegate, 3.0f, false );
}



//End of the current game and restart
void AProjectTFG_U_v1GameModeBase::OnRestartGame()
{

	UGameplayStatics::OpenLevel(GetWorld(),    FName("Level1")); //    FName(GetWorld()->GetFName()));//    FName("Level1"))
}



void AProjectTFG_U_v1GameModeBase::BeginPlay()
{
	Super::BeginPlay();


	//Particules impact system
	//ImpactFX=CreateImpactFX(BPImpactFX);
	
	
}

