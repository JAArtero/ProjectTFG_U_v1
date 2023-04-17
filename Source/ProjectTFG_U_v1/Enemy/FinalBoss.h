// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectTFG_U_v1/Enemy/Enemy.h"
#include "ProjectTFG_U_v1/Enemy/RayProjectile.h"
#include "FinalBoss.generated.h"

UENUM(BlueprintType)
enum class EAttackType: uint8
{
	A_Melee  UMETA(Displayname="Melee_Attack"),
	A_Magic  UMETA(Displayname="Magic_Attack")
};
UCLASS()
class PROJECTTFG_U_V1_API AFinalBoss : public AEnemy
{
	GENERATED_BODY()
public:
	// Sets default values for this character's properties
	AFinalBoss();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	//Radial Damage Declarations
	UPROPERTY(EditDefaultsOnly, Category="Stats")
	float ExplosionRadius {1000.0f};
	
	UPROPERTY(EditDefaultsOnly, Category="Stats")
	float ExplosionDamage {30.0f};
	
	UPROPERTY(EditAnywhere, Category="Stats")
	float ImpulsePower {1000.0f};
	
	//Magic Particles
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USceneComponent* RayProjectile;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<ARayProjectile>ProjectileType;

	void OnArmsOverlap(
	   UPrimitiveComponent* OverlappedComponent,
	   AActor* OtherActor,
	   UPrimitiveComponent* OthrerComp,
	   int32 OtherBodyIndex,
	   bool bFromSweep,
	   const FHitResult& SweepResult);

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=Weapon, meta=(AllowPrivateAccess="true"))
	class USkeletalMeshComponent* SocketforDistance;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attack_Animation, meta=(AllowPrivateAccess="true"))
	UParticleSystem* ImpactParticles;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Atack_Animation, meta=(AllowPrivateAccess="true"))
	float BaseApplyDamage;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attack_Animation, meta=(AllowPrivateAccess="true"))
	UAnimMontage* Attack_Enemy_Montage {nullptr};
		
	UPROPERTY(EditAnywhere, Category="CameraShake")
	TSubclassOf<UMatineeCameraShake> EnemyCameraShake;
	
	UPROPERTY()
	class  UEnemyMatineeCameraShake* EnemyPlayerCameraShake;

	UPROPERTY(EditDefaultsOnly, Category=Attack)
	float projectileRate {100.0f};
	
	FTimerHandle TimerMovement;
	FTimerHandle ProjectileTimer{};

	//Cause damage
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision", meta=(AllowPrivateAccess="true"))
	class UBoxComponent* ArmCollision;

	void ProjectileAttack(FName SocketName);
public:
	void Attack(int Type);
	void ClearTimer();

	UFUNCTION()
	void launchprojectile();

	// Active and deactive Arm Box Collision
	virtual void ActivateArmBoxCollision();
	virtual void DeactivateArmBoxCollision();
};


