// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectTFG_U_v1/PickUp/RestoreHealthPickUp.h"
#include "ProjectTFG_U_v1/MyCharacterM.h"


bool ARestoreHealthPickUp::ActivatePickUp()
{
	return CharacterM->Heal(Health);
}
