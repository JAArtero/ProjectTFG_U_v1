


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
		
				
		//Ray Light projectile
		FVector FirstPlayerLocation=GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation(); //Player location in world
		FVector ForwardVector = GetActorForwardVector(); //Front location
		ForwardVector *= ImpulsePower;
		
		
		CollisionSphere->AddImpulse(ForwardVector,NAME_None, true );
	
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
		
		}, 1.20, false); 
	}
}

