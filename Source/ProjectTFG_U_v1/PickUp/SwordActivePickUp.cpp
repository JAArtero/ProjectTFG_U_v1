// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectTFG_U_v1/PickUp/SwordActivePickUp.h"

#include "ProjectTFG_U_v1/MyCharacterM.h"
#include "ProjectTFG_U_v1/ProjectTFG_U_v1GameModeBase.h"


bool ASwordActivePickUp::ActivatePickUp()
{
	//return CharacterM->SetActivateSword(true);
	GameModeInstance = Cast<AProjectTFG_U_v1GameModeBase>(GetWorld()->GetAuthGameMode()); //you can just use GetWorld()->GetAuthGameMode();

	GameModeInstance->SetSwordMissionComplete(true);
	return CharacterM->SetActivateSwordPickUp(true);
}
