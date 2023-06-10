

#pragma once

#include "CoreMinimal.h"
#include "ProjectTFG_U_v1/Enemy/Enemy.h"
#include "ProjectTFG_U_v1/Enemy/RayProjectile.h"
#include "FromDistanceEnemy.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTTFG_U_V1_API AFromDistanceEnemy : public AEnemy
{
	GENERATED_BODY()
	
	AFromDistanceEnemy();
protected:
	
	//Magic Particles
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USceneComponent* RayProjectile;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<ARayProjectile>ProjectileType;

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=Weapon, meta=(AllowPrivateAccess="true"))
	class USkeletalMeshComponent* SocketforDistance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attack_Animation, meta=(AllowPrivateAccess="true"))
	UParticleSystem* ImpactParticles;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Atack_Animation, meta=(AllowPrivateAccess="true"))
	float BaseApplyDamage;
	
	UPROPERTY(EditAnywhere, Category="Stats")
	float ImpulsePower {12000.0f};

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attack_Animation, meta=(AllowPrivateAccess="true"))
	UAnimMontage* Attack_Enemy_Montage {nullptr};

	UPROPERTY(EditAnywhere, Category="CameraShake")
	TSubclassOf<UMatineeCameraShake> EnemyCameraShake;
	
	UPROPERTY()
	class  UEnemyMatineeCameraShake* EnemyPlayerCameraShake;
	
	UPROPERTY(EditDefaultsOnly, Category=Attack)
	float projectileRate {100.0f};
	
	FTimerHandle TimerMovement;
	void ProjectileAttack(FName SocketName);

public:
	void Attack(int Type);

};
