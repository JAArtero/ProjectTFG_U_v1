// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickUpBase.generated.h"

UCLASS()
class PROJECTTFG_U_V1_API APickUpBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickUpBase();

	void NotifyActorBeginOverlap(AActor* OtherActor) override;

	virtual bool ActivatePickUp();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

protected:

	UPROPERTY(VisibleAnywhere, Category=Components)
	class UBoxComponent* Collider {nullptr};

	UPROPERTY(VisibleAnywhere, Category=Components)
	class UStaticMeshComponent* Mesh {nullptr};
	
	UPROPERTY(VisibleAnywhere, Category=Components)
	class URotatingMovementComponent* RotateMovement {nullptr};

	class AMyCharacterM* CharacterM {nullptr};

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
