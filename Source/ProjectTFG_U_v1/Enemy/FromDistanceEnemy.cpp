// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectTFG_U_v1/Enemy/FromDistanceEnemy.h"

#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "ProjectTFG_U_v1/Enemy/RayProjectile.h"
#include "Engine/SkeletalMeshSocket.h"
#include "ProjectTFG_U_v1/MyCharacterM.h"

AFromDistanceEnemy::AFromDistanceEnemy()
{
	//Add socket for distance attack
	SocketforDistance=CreateDefaultSubobject<USkeletalMeshComponent>(FName("mouth_Socket"));
	SocketforDistance->SetupAttachment(GetMesh(), FName("mouth_Socket"));
	//Ray Particle
	RayProjectile = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Spot"));
	RayProjectile->SetupAttachment(RootComponent);
}

void AFromDistanceEnemy::ProjectileAttack(FName SocketName)
{
	//Create Fire Collision
	const USkeletalMeshSocket* Fire_Socket=GetMesh()->GetSocketByName(SocketName);
	//Create projectile
	const FActorSpawnParameters SpawnParameters;
	auto PlayerHero=Cast<AActor>(GetWorld()->GetFirstPlayerController());
	float distance=this->GetDistanceTo(PlayerHero);

	if(Fire_Socket)
	{
		const FTransform Fire_SocketTransform=Fire_Socket->GetSocketTransform(GetMesh());
		const ARayProjectile* SpawnProjectile= GetWorld()->SpawnActor<ARayProjectile>(ProjectileType,Fire_SocketTransform, SpawnParameters); //RayProjectile->GetComponentTransform(), SpawnParameters);
		USphereComponent* CollisionSphere= Cast<USphereComponent>(SpawnProjectile->GetRootComponent());
		//FHitResult FireHit;
				
		//Ray Light projectile
		FVector FirstPlayerLocation=GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation(); //Player location in world
		FVector ForwardVector = GetActorForwardVector(); //Front location
		ForwardVector *= ImpulsePower;
		//Fire Collision	
		/*const FVector StartFire=Fire_SocketTransform.GetLocation();
		const FQuat RotationFire=Fire_SocketTransform.GetRotation();
		const FVector RotationFireAxis=RotationFire.GetAxisX();
		const FVector EndFire=(StartFire+RotationFireAxis*10000.f);
		GetWorld()->LineTraceSingleByChannel(FireHit, StartFire, FirstPlayerLocation, ECC_Visibility); //Calculate direction
		DrawDebugLine(GetWorld(), StartFire, FirstPlayerLocation, FColor::Blue, false, 0.5f); */
		
		CollisionSphere->AddImpulse(ForwardVector,NAME_None, true );
	
		//if(FireHit.bBlockingHit && ImpactParticles)//Detecta si existe colisión para dibujar trayectoria e impacto, o no dibuja nada OJO
		//{
		//DrawDebugPoint(GetWorld(),FireHit.ImpactPoint, 60, FColor:: Red, false, 3.f);
		//UGameplayStatics::SpawnEmitterAtLocation(GetWorld(),ImpactParticles,FireHit.ImpactPoint);
		//auto actor=FireHit.GetActor();
		//auto owner=GetOwner();
		//UGameplayStatics::ApplyPointDamage(actor, 20.0, FireHit.ImpactNormal, FireHit, GetInstigatorController(),owner, UDamageType::StaticClass());
		//UGameplayStatics::ApplyDamage(FireHit.GetActor(),10, GetController(), this, UDamageType::StaticClass());
		//}
	}
}


void AFromDistanceEnemy::Attack(int type)
{
	
	UE_LOG(LogTemp,Warning, TEXT("Attacking metod"));
	FName SocketPlay;
	if(!Attack_Enemy_Montage) return;
	
	//Melee Attack
	if(type==1)
	{
		//Melee attack 
		FTimerHandle TimerHandle;
		SocketPlay=FName(TEXT("MeleeAttack"));
		PlayMyAnimation(Attack_Enemy_Montage,1.0f, SocketPlay,0.0f,true);
    }

	//Magic Attack
	if(type==2)
	{
		
	FTimerHandle TimerHandle;
	int32 SectionLength=0;
	SocketPlay=FName(TEXT("MagicAttack"));//Slot selected
	PlayMyAnimation(Attack_Enemy_Montage,1.0f, SocketPlay,0.0f,true);
		
	
	//Delay to fire
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, [&]()
	{
		ProjectileAttack("RightHandSocket"); 
		
	//Create Particles
	//FireLineCast("Fire_Socket");
	//FHitResult hit;
		
		
	}, 1.20, false); 
	//const FActorSpawnParameters SpawnParameters;
	//const ARayProjectile* SpawnProjectile= GetWorld()->SpawnActor<ARayProjectile>(ProjectileType, RayProjectile->GetComponentTransform(), SpawnParameters);
}
}

