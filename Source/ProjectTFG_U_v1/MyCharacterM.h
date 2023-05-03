// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectTFG_U_v1/Enemy/RayProjectile.h"
#include "GameFramework/Character.h"
#include "Sound/SoundCue.h"
#include "MatineeCameraShake.h"
#include "Blueprint/UserWidget.h"

//#include "Camera/CameraShake.h"
#include "ProjectTFG_U_v1/HUD/MyHUDWidget.h"
#include "ProjectTFG_U_v1/HUD/Blood_Code_UW.h"
#include "ProjectTFG_U_v1/HUD/PauseMenuUW.h"
#include "ProjectTFG_U_v1/HUD/DeathUW.h"
#include "Components/BoxComponent.h"
#include "HUD/MapMenuUW.h"

//Ojo al final de los includes
#include "MyCharacterM.generated.h"


//Create Delegate
UCLASS()
class PROJECTTFG_U_V1_API AMyCharacterM : public ACharacter
{
	GENERATED_BODY()

	
private:
	
	//Add my movement objects functions declarations
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera, meta=(AllowPrivateAccess="true"))
	class USpringArmComponent* CameraBoom;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera, meta=(AllowPrivateAccess="true"))
	class UCameraComponent* FollowCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=Weapon, meta=(AllowPrivateAccess="true"))
	class USkeletalMeshComponent* KatanaInHand;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=Weapon, meta=(AllowPrivateAccess="true"))
	class USkeletalMeshComponent* KatanaInBack;

	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera, meta=(AllowPrivateAccess="true"))
	float  BaseTurnRate;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera, meta=(AllowPrivateAccess="true"))
	float BaseLookUpRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Hit, meta=(AllowPrivateAccess="true"))
	bool bHitEvent;

	//Weapon Sound
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Sound, meta=(AllowPrivateAccess="true"))
	USoundCue* SC_Change_Weapon_Sound;
	
	//Open Dialog Sound
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Sound, meta=(AllowPrivateAccess="true"))
	USoundCue* SC_Open_Dialog;
	
	//Animations
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attack_Animation, meta=(AllowPrivateAccess="true"))
	UAnimMontage* Great_Sword_Montage;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attack_Animation, meta=(AllowPrivateAccess="true"))
	UAnimMontage* Magic_Montage;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attack_Animation, meta=(AllowPrivateAccess="true"))
	UAnimMontage* Arc_Montage;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attack_Animation, meta=(AllowPrivateAccess="true"))
	UAnimMontage* Attack_Animation_Montage {nullptr};
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attack_Animation, meta=(AllowPrivateAccess="true"))
	UParticleSystem* ImpactParticles;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Animation, meta=(AllowPrivateAccess="true"))
	bool bIsTumble;

	//Stats 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Stats, meta=(AllowPrivateAccess="true"))
	float Health {100.0f};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Stats, meta=(AllowPrivateAccess="true"))
	float MAX_HEALTH {100.0f};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Stats, meta=(AllowPrivateAccess="true"))
	float MagicForce {100.0f};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Stats, meta=(AllowPrivateAccess="true"))
	float MAX_MagicForce {100.0f};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Stats, meta=(AllowPrivateAccess="true"))
	float MAX_MAGICATTACK {4.0f};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Stats, meta=(AllowPrivateAccess="true"))
	float MagicRest {0.0f};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Stats, meta=(AllowPrivateAccess="true"))
	float MagicRestoreVelocity {1.0f};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Stats, meta=(AllowPrivateAccess="true"))
	float HealthRestoreVelocity {1.0f};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Stats, meta=(AllowPrivateAccess="true"))
	float Points {0.0f};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Stats, meta=(AllowPrivateAccess="true"))
	int CurrentLevel {0};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Stats, meta=(AllowPrivateAccess="true"))
	float MAX_Level{100.0f};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Stats, meta=(AllowPrivateAccess="true"))
	float NextLevelPoints{100.0f};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Stats, meta=(AllowPrivateAccess="true"))
	bool isDead {false};
	
    
	
	//Camera Shake
	UPROPERTY(EditAnywhere)
	TSubclassOf<UMatineeCameraShake> MyCameraShake;
	UPROPERTY()
	class  UMyMatineeCameraShake* PlayerCameraShake;

	//HUDs system
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UMyHUDWidget> PlayerHUDClass;
	
	UPROPERTY()
	class UMyHUDWidget* UIPlayerHUD;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UBlood_Code_UW> BloodWClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UPauseMenuUW> PauseMenuClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UDeathUW> DeathMenuClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UMapMenuUW>MapMenuClass;
	
	//Collision box for Sword
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision", meta=(AllowPrivateAccess="true"))
	UBoxComponent* SwordCollision;
	
	//Damage caused Sword
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Atack_Animation, meta=(AllowPrivateAccess="true"))
	float BaseDamage {20};
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Atack_Animation, meta=(AllowPrivateAccess="true"))
	float BaseMagicDamage {10};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Atack_Animation, meta=(AllowPrivateAccess="true"))
	bool bSwordIsActive{false};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Atack_Animation, meta=(AllowPrivateAccess="true"))
	bool bMagicIsActive{false};
	
	
	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
	virtual void OnDead();
	
	
public:
	// Sets default values for this character's properties
	AMyCharacterM();

	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	void AddScore(float score);
	
	
	
protected:
	//My controller Bindings
	void MoveForward(float Value);
	void MoveRight(float Value);
	void TurnAtRate(float Rate);
	void LookAtRate(float Rate);
	void RunStart();
	void RunStop();
	void TumbleStart();
	void TumbleStop();
	void Pause();
	void Map();

	//Weapons
	//Attack Action
	void Fire();
	void HardFire();
	
	//Select Weapons
	void WeaponSelection1();
	void WeaponSelection2();
	void WeaponSelection3();

    void DisableMovement();
	void EnableMovement();

	//Control Stats 
	void UpdateHealtBarHUD(float LiveValue);
	void UpdateMagicForceBarHUD();
	void RestoreMagicLevel();
	void RestoreHealthLevel();
	void UpdateLevelHUD(int Level, float PercentNumber, float NextLevelPoints);
	
	//Magic Particles
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USceneComponent* RayProjectile;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<ARayProjectile>ProjectileType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float SpawnMult=1000.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float WalkVelocity;
	
	//Radial Damage Declarations
	UPROPERTY(EditDefaultsOnly, Category=Stats)
	float ExplosionRadius {300.0f};
	
	UPROPERTY(EditDefaultsOnly, Category=Stats)
	float ExplosionDamage {30.0f};
	
	
  UFUNCTION()
	void OnSwordOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OthrerComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);
	
private:
	
	//Weapon system
	int weaponSelectionKey;
	
	//Play Animations
	int32 PlayMyAnimation(UAnimMontage* MontageToPlay, float InPlayRate, FName SlotName, float InTimeToStartMontageAt, bool Delay);

	//Create Particules
	void CreateFireParticules(FString SocketName);
	void FireLineCast(FName SocketName);

		
	FTimerHandle TimerMovement;
	UCharacterMovementComponent* MoveCompRef = nullptr;

	//Add Game instance
	class UProjectGameInstance* MyGameInstance;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	int GetWeaponSelected() const {return weaponSelectionKey;};
    float GetWalkVelocity() const {return WalkVelocity;};
	bool GetIsTumble() const {return bIsTumble;};
	UFUNCTION(BlueprintCallable )bool GetIsDeathPlayer() const {return isDead;};
	UFUNCTION(BlueprintCallable )bool GetHitEvent() const {return bHitEvent;};
	UFUNCTION(BlueprintCallable) void RestoreFromGameInstance();

	// Active and deactive sword Box Collision
	virtual void ActivateSwordBoxCollision();
	virtual void DeactivateSwordBoxCollision();
	void ViewDeathMenu();

	//Relations PickUp
	bool SetActivateSwordPickUp(bool iSActive);  // {MyGameInstance->PlayerbSwordIsActive=iSActive; return SetActivateSword();};
    bool SetActivateSword();//bool ActiveSword);
	//FORCEINLINE
	bool SetActiveMagic();//bool ActiveMagic);
	//FORCEINLINE
	bool  Heal( float amount);

	
	
	virtual void NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved,
		FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;
};
