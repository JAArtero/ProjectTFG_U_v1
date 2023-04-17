// **************************************************************************************************
// *********************************** Create impact fire ******************************************* 
// **************************************************************************************************


#include "ProjectTFG_U_v1/HUD/GameHUD.h"

#include "Blueprint/UserWidget.h"
#include "Components/EditableText.h"
#include "Engine/Canvas.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Math/Color.h"

/*
UGameHUD::AGameHUD()
{
	//Create Cross Fire HUD
	static ConstructorHelpers::FObjectFinder<UTexture2D> Crosshair(TEXT("/Game/IMG/CrossHUD/Anchor"));
	
	if(Crosshair.Object)
	{
		CrossTexture=Crosshair.Object;
	}
	
}*/
/*
void UGameHUD::DrawHUD()
{
	Super::DrawHUD();

	if(CrossTexture)
	{
		float ScreenXSize=(Canvas->SizeX/2)-32;
		float ScreenYSize=(Canvas->SizeY/2)-32;
		//Draw Point
		//DrawTexture(CrossTexture,ScreenXSize,ScreenYSize, 64,64, 0,0,1,1);
	}
}
*/

void UGameHUD::SetHealth(float CurrentHealth, float MaxHealth)
{
	if (HealthBar)
	{
		HealthBar->SetPercent(CurrentHealth );
	}
}

void UGameHUD::SetPower(float CurrentPower, float MaxPower)
{
	if (MagicBar)
	{
		MagicBar->SetPercent(CurrentPower / MaxPower);
	}
}

void UGameHUD::SetLevel(float CurrentLevel, float MaxLevel)
{

	if (LevelBar)
	{
		LevelBar->SetPercent(CurrentLevel / MaxLevel);
		Level->SetText(FText::AsNumber(CurrentLevel));
	}
}


void UGameHUD::SetWeaponImage(int weapon)
{
	
	
}
