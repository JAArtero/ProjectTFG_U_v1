

#pragma once

#include "CoreMinimal.h"
#include "ProjectTFG_U_v1/PickUp/PickUpBase.h"
#include "KeyFinalBoss.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTTFG_U_V1_API AKeyFinalBoss : public APickUpBase
{
	GENERATED_BODY()
public:

	bool ActivatePickUp() override;

protected:
	UPROPERTY(EditDefaultsOnly, Category=Stats)
	bool KeyActive {true};
};