// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ImpactFX.generated.h"

UCLASS()
class PROJECTTFG_U_V1_API AImpactFX : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AImpactFX();
	void CreateImpactSound(const FHitResult& hit);
	void CreateImpactParticles(const FHitResult& hit);
	
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
protected:
	UPROPERTY(EditDefaultsOnly, Category="FX")
	USoundBase* ImpactSound {nullptr};
	UPROPERTY(EditDefaultsOnly, Category="FX")
	UParticleSystem* ImpactParticles{nullptr};

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
