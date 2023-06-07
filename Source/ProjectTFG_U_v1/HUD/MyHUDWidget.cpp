// Fill out your copyright notice in the Description page of Project Settings.

#include "MyHUDWidget.h"
#include "Blueprint/UserWidget.h"
#include "Components/EditableText.h"
#include "Components/Image.h"
#include "Engine/Canvas.h"
#include "Components/ProgressBar.h"
#include "Components/WidgetSwitcher.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"



void UMyHUDWidget::SetHealth(float CurrentHealth, float MaxHealth)
{
	if (HealthBar)
	{
		HealthBar->SetPercent(CurrentHealth /MaxHealth );
	}
}

void UMyHUDWidget::SetMagic(float CurrentMagic, float MaxMagic)
{
	if (MagicBar)
	{
		MagicBar->SetPercent(CurrentMagic / MaxMagic);
	}
}

void UMyHUDWidget::SetLevel( float Points, float MaxLevel, float NextLevelPoints, float PercentNumber)
{
	
	if (LevelBar && ActualPoints && PointsNextLevel)
	{
		LevelBar->SetPercent(PercentNumber / MaxLevel);
		ActualPoints->SetText(FText::AsNumber(Points));
		PointsNextLevel->SetText(FText::AsNumber(NextLevelPoints));
	}
}

void UMyHUDWidget::SetLevelNumber(int Level)
{
	if(	CurrentLevelText)
	{
        CurrentLevelText->SetText(FText::AsNumber(Level));
	
	}
}

void UMyHUDWidget::SetImageWeapon(int weapon)
{
	//Change image in UI
	SelectWeapon->SetActiveWidgetIndex(weapon);
}

void UMyHUDWidget::SetSwordAvailable(int32 Activate)
{
	if(Activate==1)
	{
		WeaponAvailableSword->SetActiveWidgetIndex(1);
	}else
	{
		WeaponAvailableSword->SetActiveWidgetIndex(0);
	}
}


void UMyHUDWidget::SetMagicAvailable(int32 Activate)
{
	if(Activate==1)
	{
		WeaponsAvailableMagic->SetActiveWidgetIndex(1);
	}else
	{
		WeaponsAvailableMagic->SetActiveWidgetIndex(0);

	}
}
