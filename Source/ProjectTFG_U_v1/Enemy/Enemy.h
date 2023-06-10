

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MatineeCameraShake.h"
#include "Enemy.generated.h"



UCLASS()
class PROJECTTFG_U_V1_API AEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemy();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
protected:
	UPROPERTY(EditDefaultsOnly, Category=Components)
	class UHealthComponent*  Health {nullptr};
	void DisableMovement();
	void EnableMovement();
    void UpdateScore(float points);
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UFUNCTION()
	void OnDead(AActor *DamagedActor, float Damage,const class UDamageType* DamageType, class AController* InstigateBy, AActor* DamageCauser);

	UFUNCTION()
	void OnDamage(float ActualLfe);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attack_Animation, meta=(AllowPrivateAccess="true"))
	UAnimMontage* DamageAnimation {nullptr};
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attack_Animation, meta=(AllowPrivateAccess="true"))
	float BaseApplyScoreMagic {10.f};

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Attack_Animation, meta=(AllowPrivateAccess="true"))
	float BaseApplyScoreMelee {10.f};
	
	FTimerHandle TimerMovement;
	
public:
	int32 PlayMyAnimation(UAnimMontage* MontageToPlay, float InPlayRate, FName SlotName, float InTimeToStartMontageAt, bool Delay);

};
