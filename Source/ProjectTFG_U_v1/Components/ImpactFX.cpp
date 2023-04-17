// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectTFG_U_v1/Components/ImpactFX.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
AImpactFX::AImpactFX()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AImpactFX::CreateImpactSound(const FHitResult& hit)
{
	if(!ImpactSound) return;

	if(!GetWorld()) return;
	UGameplayStatics::PlaySoundAtLocation(GetWorld(), ImpactSound, hit.ImpactPoint);
}

void AImpactFX::CreateImpactParticles(const FHitResult& hit)
{
	if(!ImpactParticles) return;

	if(!GetWorld()) return;

	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactParticles, hit.ImpactPoint, hit.ImpactNormal.Rotation(), true);

	
}


// Called when the game starts or when spawned
void AImpactFX::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AImpactFX::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

