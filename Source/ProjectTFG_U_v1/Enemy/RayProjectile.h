// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/PointLightComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "RayProjectile.generated.h"

UCLASS()
class PROJECTTFG_U_V1_API ARayProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARayProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USphereComponent* CollisionSphere;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)	
	UParticleSystemComponent* Particle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UPointLightComponent* SpotLightComponent;

	UPROPERTY(EditDefaultsOnly, Category="Collision")
	float BaseDamage {20.0f};

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Animation", meta=(AllowPrivateAccess="true"))
	UParticleSystem* ImpactParticles;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Sound, meta=(AllowPrivateAccess="true"))
	USoundBase* SC_Impact_Sound;
	
/*	
	//Control Overlap 
	UFUNCTION()
	void OnProjectileOverlap(
	   UPrimitiveComponent* OverlappedComponent,
	   AActor* OtherActor,
	   UPrimitiveComponent* OthrerComp,
	   int32 OtherBodyIndex,
	   bool bFromSweep,
	   const FHitResult& SweepResult);

	*/



	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved,
		FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;

	
};
