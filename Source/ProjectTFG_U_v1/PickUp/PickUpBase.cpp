// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectTFG_U_v1/PickUp/PickUpBase.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "ProjectTFG_U_v1/MyCharacterM.h"

// Sets default values
APickUpBase::APickUpBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Creating Components
	Collider=CreateDefaultSubobject<UBoxComponent>(FName("Collider"));
	SetRootComponent(Collider);
	Mesh=CreateDefaultSubobject<UStaticMeshComponent>(FName("Mesh"));
	Mesh->SetupAttachment(GetRootComponent());

	//Create Rotation
	RotateMovement=CreateDefaultSubobject<URotatingMovementComponent>(FName("RotateMove"));

}

// Called when the game starts or when spawned
void APickUpBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickUpBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APickUpBase::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	CharacterM=Cast<AMyCharacterM>(OtherActor);
	if(!CharacterM) return;

	if(ActivatePickUp())
		Destroy();
}

bool APickUpBase::ActivatePickUp()
{
	return false;
}
