// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectTFG_U_v1/Enviorement/Barrel.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"
#include "ProjectTFG_U_v1/Components/HealthComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
ABarrel::ABarrel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh=CreateDefaultSubobject<UStaticMeshComponent>(FName("Mesh"));
	SetRootComponent(Mesh);
		
	Health=CreateDefaultSubobject<UHealthComponent>(FName("HealtComponent"));
}



// Called when the game starts or when spawned
void ABarrel::BeginPlay()
{
	Super::BeginPlay();
	if(!Health) return;
	Health->OnDead.AddDynamic(this, &ABarrel::OnBarrelDead);
}

// Called every frame
void ABarrel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void ABarrel::OnBarrelDead(AActor *DamagedActor, float Damage,const class UDamageType* DamageType, class AController* InstigateBy, AActor* DamageCauser)
{
	//Sound of explosion
	if(!ExplosionSound) return;
	UGameplayStatics::PlaySoundAtLocation(GetWorld(), ExplosionSound, GetActorLocation());

	//Particles of explosion
	if(!ExplosionParticles) return;
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionParticles, GetActorTransform());

	Destroy();
}