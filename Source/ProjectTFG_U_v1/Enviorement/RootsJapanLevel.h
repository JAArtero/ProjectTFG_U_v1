// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RootsJapanLevel.generated.h"

UCLASS()
class PROJECTTFG_U_V1_API ARootsJapanLevel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARootsJapanLevel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:

	UPROPERTY(VisibleAnywhere,Category=Components)
	class UStaticMeshComponent* Mesh {nullptr};

	UPROPERTY(VisibleAnywhere, Category=Components)
	class	UHealthComponent* Health {nullptr};

	UPROPERTY(EditDefaultsOnly, Category=FX)
	USoundBase* ExplosionSound {nullptr};

	UPROPERTY(EditDefaultsOnly, Category=FX)
	UParticleSystem* ExplosionParticles {nullptr};
	
private:
	UFUNCTION()
	void OnDeathRoot(AActor *DamagedActor, float Damage,const class UDamageType* DamageType, class AController* InstigateBy, AActor* DamageCauser);
		
};
