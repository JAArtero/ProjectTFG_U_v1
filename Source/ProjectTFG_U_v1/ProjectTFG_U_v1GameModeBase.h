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

protected:
	void BeginPlay() override;

public:
	AProjectTFG_U_v1GameModeBase();

	FAddScorepointsDelegate AddScore;
	FUpdateScorepointsDelegate UpodateScore;

	
	void RestartGameTimer();

	UFUNCTION(BlueprintCallable)
	int selecIndexTalk();

		
private:
	UFUNCTION()
	void OnRestartGame();
	FTimerHandle RestartGame_TimerHandle{};

	UPROPERTY(EditDefaultsOnly, Category=Missions)
	bool initTalk {false};

	UPROPERTY(EditDefaultsOnly, Category=Missions)
	bool SwordMissionComplete {false};
	
	UPROPERTY(EditDefaultsOnly, Category=Missions)
	bool SwordMissionMessage {false};

	UPROPERTY(EditDefaultsOnly, Category=Missions)
	bool MagicMissionComplete{false};

	UPROPERTY(EditDefaultsOnly, Category=Missions)
	bool MagicMissionMessage{false};
	
	UPROPERTY(EditDefaultsOnly, Category=Missions)
	bool RuinMissionComplete{false};
	
	UPROPERTY(EditDefaultsOnly, Category=Missions)
	bool RuinMissionMessage{false};

public:
	//Getter
	bool GetInitTalk() const;
	bool GetSwordMissionCompleteFuction() const;
	bool GetMagicMissionCompleteFuction() const;
	bool GetRuinMissionCompleteFuction() const;
    //Setter
	void SetInitTalk(const bool bInitTalk);
	void SetSwordMissionComplete(const bool bIsComplete);
	void SetMagicMissionComplete(const bool bIsComplete);
	void SetRuinMissionComplete(const bool bIsComplete);
	void SetSwordMissionMessage(const bool bSwordMissionMessage);
	void SetMagicMissionMessage(const bool bMagicMissionMessage);
	void SetRuinMissionMessage(const bool bRuinMissionMessage);
};
