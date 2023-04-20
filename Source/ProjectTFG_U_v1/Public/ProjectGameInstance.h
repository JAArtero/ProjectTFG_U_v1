// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "ProjectGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTTFG_U_V1_API UProjectGameInstance : public UGameInstance
{
	GENERATED_BODY()


	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Stats, meta=(AllowPrivateAccess="true"))
	float PlayerHealth {100.0f};

	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Stats, meta=(AllowPrivateAccess="true"))
	float PlayerMagicForce {100.0f};
	
	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Stats, meta=(AllowPrivateAccess="true"))
	float PlayerMAX_MAGICATTACK {4.0f};
	
	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Stats, meta=(AllowPrivateAccess="true"))
	float PlayerMagicRest {0.0f};
	
	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Stats, meta=(AllowPrivateAccess="true"))
	float PlayerMagicRestoreVelocity {1.0f};
	
	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Stats, meta=(AllowPrivateAccess="true"))
	float PlayerHealthRestoreVelocity {1.0f};
	
	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Stats, meta=(AllowPrivateAccess="true"))
	float PlayerPoints {50.0f};
	
	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Stats, meta=(AllowPrivateAccess="true"))
	int PlayerCurrentLevel {5};

	bool PlayerbSwordIsActive{true};
	
	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Atack_Animation, meta=(AllowPrivateAccess="true"))
	bool PlayerbMagicIsActive{false};
public:
	float GetPlayerHealth();
	void SetPlayerHealth(float PlayerHealth);
	float GetPlayerMagicForce();
	void SetPlayerMagicForce(float MagicForce);
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
	bool GetPlayerSwordIsActive() const;
	void SetPlayerSwordIsActive(bool bSwordIsActive);
	bool GetPlayerMagicIsActive() const;
	void SetPlayerMagicIsActive(bool bMagicIsActive);

	
	
};
