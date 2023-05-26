// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MeleeHitInterface.h"
#include "Components/ActorComponent.h"
//#include "MyHUDWidget.h"

#include "HealthComponent.generated.h"

//Custom Delegate
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FiveParams(FOnDeadSignature, AActor*, DamagedActor,float, Damage, const class UDamageType* ,DamageType,class AController* ,InstigatedBy,	AActor* ,DamageCauser);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDamage,float, ActualLife);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTTFG_U_V1_API UHealthComponent : public UActorComponent //, public IMeleeHitInterface
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

	bool Heal(float amount);
	
	//Damage control
	UFUNCTION()
	void OnOwnerDamage(AActor* DamageActor,
		float Damage,
		const class UDamageType* DamageType,
		class AController* InstigatedBy,
		AActor* DamageCauser);

	UFUNCTION(BlueprintCallable) float GetHealt() const {return ActualLife;};
	UFUNCTION(BlueprintCallable) bool IsDie() const {return bDie;};
	

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
	UPROPERTY(EditDefaultsOnly,Category=Stats, meta=(AllowPrivateAccess="true"))
	float ActualLife {100.0f};
	
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void UpdateHealth(float HealthDelta);
	float GetLife() const {return ActualLife;};
	float GetMaxLife() const { return MAX_LIFE;};

	//Delegates
	FOnDeadSignature OnDead;
	FOnDamage OnDamage;

	

	//Override Melee Interface
	virtual void  MeleeHit_Implementation(FHitResult HitResult);// override;
	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator,	AActor* DamageCauser);
	
private:
	bool bDie {false};
	
	UPROPERTY(EditDefaultsOnly,Category=Stats, meta=(AllowPrivateAccess="true"))
	float MAX_LIFE {100.0f};

	
};
