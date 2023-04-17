// Fill out your copyright notice in the Description page of Project Settings.


#include "RayProjectile.h"

#include "ProjectTFG_U_v1/Components/MeleeHitInterface.h"
#include "Chaos/Collision/PBDCollisionConstraintHandle.h"
#include "Components/SphereComponent.h"
#include "Components/SpotLightComponent.h"
#include "ProjectTFG_U_v1/Enemy/Enemy.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
ARayProjectile::ARayProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Collision Sphere
	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Collision Sphere"));
	CollisionSphere->SetupAttachment(RootComponent);

	//Particles
	Particle=CreateDefaultSubobject<UParticleSystemComponent>(TEXT("RayParticle"));
	Particle->SetupAttachment(CollisionSphere);
	
	//Light
	SpotLightComponent= CreateDefaultSubobject<UPointLightComponent>(TEXT("Light"));
	SpotLightComponent->SetupAttachment(CollisionSphere);

	
}

// Called when the game starts or when spawned
void ARayProjectile::BeginPlay()
{
	Super::BeginPlay();

	//CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &ARayProjectile::OnProjectileOverlap);
}	
 
/*
void ARayProjectile::OnProjectileOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OthrerComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(IsValid(SweepResult.GetActor()))
	{
		IMeleeHitInterface* MeleeHitInterface=Cast<IMeleeHitInterface>(SweepResult.GetActor());

		if(MeleeHitInterface)
		{
			MeleeHitInterface->MeleeHit_Implementation(SweepResult);
		}
	}
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red,FString::Printf(TEXT("ProjectileOverlap")));

	UGameplayStatics::ApplyDamage(SweepResult.GetActor(),BaseDamage, GetInstigatorController(), this, UDamageType::StaticClass());
}
*/
// Called every frame
void ARayProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARayProjectile::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp,
	bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	//Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);

	if(ImpactParticles)
	{
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(),ImpactParticles,Hit.ImpactPoint);		
	}

	if(SC_Impact_Sound)
	{
		UGameplayStatics::PlaySound2D(this, SC_Impact_Sound);
	}

	UGameplayStatics::ApplyDamage(Hit.GetActor(),BaseDamage, GetInstigatorController(), this, UDamageType::StaticClass());

	this->Destroy();
}

