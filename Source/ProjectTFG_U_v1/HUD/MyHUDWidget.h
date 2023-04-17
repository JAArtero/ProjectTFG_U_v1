// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/HUD.h"
#include "MyHUDWidget.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTTFG_U_V1_API UMyHUDWidget : public UUserWidget
{
	GENERATED_BODY()
	
	
	

public:
	
	/** Update HUD with current health. */
	void SetHealth(float CurrentHealth, float MaxHealth);

	/** Update HUD with current power. */
	void SetMagic(float CurrentMagic, float MaxMagic);
	
	/** Update HUD with current Level. */
	void SetLevel(float Points, float MaxLevel, float NextLevelPoints, float PercentNumber);

	/** Update Number in HUD*/
	void SetLevelNumber(int Level);

	/** Change weapon imagen selected*/
	void SetImageWeapon(int weapon);

	/** Active icon of weapon available*/
	void SetSwordAvailable(int32 Activate);

	void SetMagicAvailable(int32 Activate);

	//Health Section
	/** Widget to use to display current health. */
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UProgressBar* HealthBar;

	/** Widget to use to display current Magic level. */
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UProgressBar* MagicBar;

	//Level Section
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UProgressBar* LevelBar;
	UPROPERTY(EditAnywhere, meta = (BindWidget))   
	class UEditableText* PointsNextLevel;
	UPROPERTY(EditAnywhere, meta = (BindWidget))   
	class UEditableText* ActualPoints;
	UPROPERTY(EditAnywhere, meta = (BindWidget))   
    class UEditableText* CurrentLevelText;

	//Weapon Selection Section
	UPROPERTY(EditAnywhere, meta = (BindWidget)) 
	class UWidgetSwitcher* SelectWeapon;

	//Weapon Selection Section
	UPROPERTY(EditAnywhere, meta = (BindWidget)) 
	class UWidgetSwitcher* WeaponAvailableSword;
	
	//Weapon Selection Section
	UPROPERTY(EditAnywhere, meta = (BindWidget)) 
	class UWidgetSwitcher* WeaponsAvailableMagic;

	
	
};
