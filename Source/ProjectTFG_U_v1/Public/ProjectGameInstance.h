//Trabajo de Fin de Grado de la UOC de Jose Atonio Artero Férnandez

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "ProjectGameInstance.generated.h"


UCLASS()
class PROJECTTFG_U_V1_API UProjectGameInstance : public UGameInstance
{
	GENERATED_BODY()


public:
	UProjectGameInstance();
	
protected:
	virtual void Init() override;

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Stats)  
	float PlayerHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Stats)
	float PlayerMaxHealth;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite,  Category=Stats)
	float PlayerMagicForce;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,  Category=Stats)
	float PlayerMaxMagicForce;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,  Category=Stats)
	float PlayerMAX_MAGICATTACK;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite,  Category=Stats)
	float PlayerMagicRest;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite,  Category=Stats)
	float PlayerMagicRestoreVelocity;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Stats)
	float PlayerHealthRestoreVelocity;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Stats)
	float PlayerPoints;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Stats)
	int PlayerCurrentLevel;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Stats)
	float PlayerMAX_Level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Stats)
	float PlayerNextLevelPoints;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Stats)
	bool PlayerbSwordIsActive;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=stats)
	bool PlayerbMagicIsActive;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,  Category=Missions)
	bool initTalk {false};

	UPROPERTY(EditAnywhere, BlueprintReadWrite,  Category=Missions)
	bool SwordMissionComplete {false};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite,  Category=Missions)
	bool SwordMissionMessage {false};

	UPROPERTY(EditAnywhere, BlueprintReadWrite,  Category=Missions)
	bool MagicMissionComplete{false};

	UPROPERTY(EditAnywhere, BlueprintReadWrite,  Category=Missions)
	bool MagicMissionMessage{false};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite,  Category=Missions)
	bool RuinMissionComplete{false};
	


public:
	void DeathMenu();

	//Timer for restore levels
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=stats)
	FTimerHandle TimerMovementGI;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=stats)
	FTimerHandle TimerMagicGI;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=stats)
	FTimerHandle TimerRestoreHealthGI;
	FTimerHandle TimerHandle1;
	FTimerHandle TimerHandle2;
	FTimerHandle TimerHandle3;
	FTimerHandle TimerHandle4;
	FTimerHandle TimerHandle5;

	
	//Getters and Setters
	
	bool GetIsPlaying();
	void SetIsPlaying(bool bIsPlaying);

	float GetPlayerNextLevelPoints();
	void SetPlayerNextLevelPoints(float PlayerNextLevelPoints);

	float GetPlayerMax_Level();
	void SetPlayerMax_Level(float PlayerMax_Level);

	float GetPlayerHealth();
	void SetPlayerHealth(float PlayerHealth);

	float GetPlayerMaxHealth() ;
	void SetPlayerMaxHealth(float PlayerHealth);
	
	float GetPlayerMagicForce();
	void SetPlayerMagicForce(float MagicForce);

	float GetPlayerMaxMagicForce();
	void SetPlayerMaxMagicForce(float MaxMagicForce);
	
	float GetPlayerMax_Magicattack();
	void SetPlayerMax_Magicattack(float Max_Magicattack);
	
	float GetPlayerMagicRest();
	void SetPlayerMagicRest(float MagicRest);
	
	float GetPlayerMagicRestoreVelocity();
	void SetPlayerMagicRestoreVelocity(float MagicRestoreVelocity);
	
	float GetPlayerHealthRestoreVelocity() ;
	void SetPlayerHealthRestoreVelocity(float HealthRestoreVelocity);
	
	float GetPlayerPoints() ;
	void SetPlayerPoints(float Points);
	
	int GetPlayerCurrentLevel() ;
	void SetPlayerCurrentLevel(int CurrentLevel);
	
	bool GetPlayerSwordIsActive() ;
	void SetPlayerSwordIsActive(bool bSwordIsActive);
	
	bool GetPlayerMagicIsActive() ;
	void SetPlayerMagicIsActive(bool bMagicIsActive);
	
};
