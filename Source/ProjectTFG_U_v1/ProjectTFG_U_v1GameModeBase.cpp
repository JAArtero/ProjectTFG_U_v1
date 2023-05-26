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

void AProjectTFG_U_v1GameModeBase::BeginPlay()
{
	Super::BeginPlay();

	//Particules impact system
	//ImpactFX=CreateImpactFX(BPImpactFX);
}
//Create Timer to restart game 
void AProjectTFG_U_v1GameModeBase::RestartGameTimer()
{
	FTimerDynamicDelegate restartDelegate{};
	restartDelegate.BindUFunction(this, FName("OnRestartGame"));
	GetWorldTimerManager().SetTimer(RestartGame_TimerHandle, restartDelegate, 3.0f, false );
}

int AProjectTFG_U_v1GameModeBase::selecIndexTalk()
{

	if(!initTalk)
	{
		SetInitTalk(true);
		return 0;
	};
	if(!SwordMissionComplete && !SwordMissionMessage && initTalk)
	{
		SetSwordMissionMessage(true);
		return 1;
	};
	if(!MagicMissionComplete && !MagicMissionMessage && SwordMissionComplete && initTalk)
	{
		SetMagicMissionMessage(true);
		return 2;
	};
	if(!RuinMissionComplete &&!RuinMissionMessage && MagicMissionComplete && SwordMissionComplete && initTalk)
	{
		SetRuinMissionMessage(true);
		return 3;
	};

	return FMath::RandRange( 4,  7);

	
}


//End of the current game and restart
void AProjectTFG_U_v1GameModeBase::OnRestartGame()
{

	UGameplayStatics::OpenLevel(GetWorld(),    FName("Level1")); //    FName(GetWorld()->GetFName()));//    FName("Level1"))
}

//Setters
void AProjectTFG_U_v1GameModeBase::SetSwordMissionMessage(const bool bSwordMissionMessage)
{
	SwordMissionMessage = bSwordMissionMessage;
}

void AProjectTFG_U_v1GameModeBase::SetMagicMissionMessage(const bool bMagicMissionMessage)
{
	MagicMissionMessage = bMagicMissionMessage;
}

void AProjectTFG_U_v1GameModeBase::SetRuinMissionMessage(const bool bRuinMissionMessage)
{
	RuinMissionMessage = bRuinMissionMessage;
}

//Getters
bool AProjectTFG_U_v1GameModeBase::GetInitTalk() const
{
	return initTalk;
}

bool AProjectTFG_U_v1GameModeBase::GetSwordMissionCompleteFuction() const
{
	return SwordMissionComplete;
}

bool AProjectTFG_U_v1GameModeBase::GetMagicMissionCompleteFuction() const
{
	return MagicMissionComplete;
}

bool AProjectTFG_U_v1GameModeBase::GetRuinMissionCompleteFuction() const
{
	return RuinMissionComplete;
}


//Setters
void AProjectTFG_U_v1GameModeBase::SetInitTalk(const bool bInitTalk)
{
	initTalk = bInitTalk;
}

void AProjectTFG_U_v1GameModeBase::SetSwordMissionComplete(const bool bIsComplete)
{
	SwordMissionComplete = bIsComplete;
}

void AProjectTFG_U_v1GameModeBase::SetMagicMissionComplete(const bool bIsComplete)
{
	MagicMissionComplete = bIsComplete;
}

void AProjectTFG_U_v1GameModeBase::SetRuinMissionComplete(const bool bIsComplete)
{
	RuinMissionComplete = bIsComplete;
}


