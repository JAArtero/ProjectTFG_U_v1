


#include "ProjectTFG_U_v1/PickUp/KeyFinalBoss.h"
#include "ProjectTFG_U_v1/MyCharacterM.h"


bool AKeyFinalBoss::ActivatePickUp()
{
	return CharacterM->SetActiveKey();
}