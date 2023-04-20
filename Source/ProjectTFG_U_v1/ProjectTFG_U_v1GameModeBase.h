// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ProjectTFG_U_v1GameModeBase.generated.h"




DECLARE_DELEGATE_OneParam(FAddScorepointsDelegate, float);
DECLARE_DELEGATE_OneParam(FUpdateScorepointsDelegate, float);
UCLASS()
class AProjectTFG_U_v1GameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	AProjectTFG_U_v1GameModeBase();

	FAddScorepointsDelegate AddScore;
	FUpdateScorepointsDelegate UpodateScore;

	
	void RestartGameTimer();

		
private:
	UFUNCTION()
	void OnRestartGame();
	FTimerHandle RestartGame_TimerHandle{};

protected:
	void BeginPlay() override;


};
