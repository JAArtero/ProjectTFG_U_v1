// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectTFG_U_v1/PickUp/SwordActivePickUp.h"

#include "ProjectTFG_U_v1/MyCharacterM.h"


bool ASwordActivePickUp::ActivatePickUp()
{
	//return CharacterM->SetActivateSword(true);
	return CharacterM->SetActivateSwordPickUp(true);
}
