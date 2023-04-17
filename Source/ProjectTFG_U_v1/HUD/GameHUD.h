// **************************************************************************************************
// *********************************** Create HUD ******************************************* 
// **************************************************************************************************
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Blueprint/UserWidget.h"
#include "GameHUD.generated.h"



/**
 * 
 */
UCLASS()
class PROJECTTFG_U_V1_API UGameHUD : public UUserWidget
//class PROJECTTFG_U_V1_API AGameHUD : public AHUD
{
	GENERATED_BODY()

	UTexture2D* CrossTexture;

	


public:

	//AGameHUD();

	//virtual void DrawHUD() override;

	/*UPROPERTY(EditAnywhere,  Category = "Widgets")
	TSubclassOf<class UUserWidget> WBuildMenu;

	UPROPERTY(EditAnywhere, Category = "Widgets")
	AGameHUD* UBuildMenu;*/

	/** Update HUD with current health. */
	void SetHealth(float CurrentHealth, float MaxHealth);

	/** Update HUD with current Magic */
	void SetPower(float CurrentPower, float MaxPower);

	/** Update HUD with current Level. */
	void SetLevel(float CurrentLevel, float MaxLevel);

	/** Change Image of Weapon Selected*/
	void SetWeaponImage(int weapon);

	
	
	
	/** Widget to use to display current health. */
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UProgressBar* HealthBar;

	/** Widget to use to display current power. */
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UProgressBar* MagicBar;

	/** Widget to use to display current power. */
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UProgressBar* LevelBar;

	UPROPERTY(EditAnywhere, meta = (BindWidget))   
	class UEditableText* Level; 
	UPROPERTY(EditAnywhere, meta = (BindWidget))   
	class UTextBlock* NextLevel;


	
};
