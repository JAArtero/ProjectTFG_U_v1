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

	
	
	//class AImpactFX* CreateImpactFX(UClass* ImpactfxClass);
	
private:
	UFUNCTION()
	void OnRestartGame();

public:
	
	//class AImpactFX* ImpactFX {nullptr};
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HUDWindget")
	//TSubclassOf<class UMyHUDWidget> UIPlayerHUD;
	

	
private:
	FTimerHandle RestartGame_TimerHandle{};

protected:
	void BeginPlay() override;

protected:

	//UPROPERTY(EditDefaultsOnly, Category="FX")
	//TSubclassOf<class AImpactFX> BPImpactFX{};

};
