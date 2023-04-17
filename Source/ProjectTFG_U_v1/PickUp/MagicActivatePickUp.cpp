// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectTFG_U_v1/PickUp/MagicActivatePickUp.h"
#include "ProjectTFG_U_v1/MyCharacterM.h"


bool AMagicActivatePickUp::ActivatePickUp()
{
	return CharacterM->SetActiveMagic(true);

}
