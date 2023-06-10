


#include "ProjectTFG_U_v1/Enemy/FinalBoss.h"

#include "Components/BoxComponent.h"
#include "Engine/SkeletalMeshSocket.h"
#include "Kismet/GameplayStatics.h"
#include "ProjectTFG_U_v1/Enemy/RayProjectile.h"
#include "ProjectTFG_U_v1/Components/MeleeHitInterface.h"



AFinalBoss::AFinalBoss()
{
	// Sets default values for this character's properties
	//Add socket for distance attack
	SocketforDistance=CreateDefaultSubobject<USkeletalMeshComponent>(FName("mouth_Socket"));
	SocketforDistance->SetupAttachment(GetMesh(), FName("mouth_Socket"));
	
	//Ray Particle
	RayProjectile = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Spot"));
	RayProjectile->SetupAttachment( RootComponent );//SocketforDistance);     //RootComponent);

	//Create Arm box Collision
	ArmCollision=CreateDefaultSubobject<UBoxComponent>(TEXT("Arm Collision Box"));
	ArmCollision->SetupAttachment(GetMesh(), FName("hand_r"));
}

void AFinalBoss::BeginPlay()
{
	Super::BeginPlay();

	ArmCollision->OnComponentBeginOverlap.AddDynamic(this,  &AFinalBoss::OnArmsOverlap);
	ArmCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	ArmCollision->SetCollisionObjectType(ECC_WorldDynamic);
	ArmCollision->SetCollisionResponseToChannels(ECR_Ignore);
	ArmCollision->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
}

void AFinalBoss::OnArmsOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
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
	//Apply Damage to Enemy
	//UGameplayStatics::ApplyDamage(SweepResult.GetActor(),BaseApplyDamage, GetController(), this, UDamageType::StaticClass());
}

void AFinalBoss::ActivateArmBoxCollision()
{
	ArmCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
}

void AFinalBoss::DeactivateArmBoxCollision()
{
	ArmCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AFinalBoss::Attack(int type)
{
	UE_LOG(LogTemp,Warning, TEXT("Attacking metod"));
	FName SocketPlay;
	if(!Attack_Enemy_Montage) return;
		
	if(type==1)
	{
		//Melee attack 
		FTimerHandle TimerHandle;
		SocketPlay=FName(TEXT("MeleeAttack"));
		PlayMyAnimation(Attack_Enemy_Montage,1.0f, SocketPlay,0.0f,true);
    
	
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, [&]()
			{
				if(EnemyCameraShake)
				{
					UMatineeCameraShake::StartMatineeCameraShake(GetWorld()->GetFirstPlayerController()->PlayerCameraManager,
						EnemyCameraShake,
						2.0f,
						ECameraShakePlaySpace::CameraLocal,
						FRotator::ZeroRotator);
				}
				//Radial Damage
				TArray<AActor*> igfnoredActors{};
				igfnoredActors.Add(this);
				UGameplayStatics::ApplyRadialDamage(
					GetWorld(),
					ExplosionDamage,
					GetActorLocation(),
					ExplosionRadius,
					UDamageType::StaticClass(),
					igfnoredActors,
					this,
					GetInstigatorController(),
					true);
			}, 2.50, false);
	}

	//Attack type Distance
	if(type==2)
	{
		//Attack 2
		FTimerHandle TimerHandle;
		SocketPlay=FName(TEXT("MagicAttack"));//Slot selected
		PlayMyAnimation(Attack_Enemy_Montage,1.0f, SocketPlay,0.0f,true);
		if(EnemyCameraShake)
			{
					UMatineeCameraShake::StartMatineeCameraShake(GetWorld()->GetFirstPlayerController()->PlayerCameraManager,
						EnemyCameraShake,
						2.0f,
						ECameraShakePlaySpace::CameraLocal,
						FRotator::ZeroRotator);
			}
					
		FTimerDynamicDelegate ProjectileDelegate{};
		ProjectileDelegate.BindUFunction(this, FName("launchprojectile"));
		GetWorldTimerManager().SetTimer(ProjectileTimer, ProjectileDelegate, projectileRate, true, 2.0f);
	}
}

void AFinalBoss::ClearTimer()
{
	GetWorldTimerManager().ClearTimer(ProjectileTimer);
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Blue,FString::Printf(TEXT("Clear Timer")));

}

void AFinalBoss::launchprojectile()
{
	ProjectileAttack("mouth_Socket");
}

void AFinalBoss::ProjectileAttack(FName SocketName)
{
	//Create Fire Collision
	const USkeletalMeshSocket* Fire_Socket=GetMesh()->GetSocketByName(SocketName);
	//Create projectile
	const FActorSpawnParameters SpawnParameters;

	if(Fire_Socket)
	{
		const FTransform Fire_SocketTransform=Fire_Socket->GetSocketTransform(GetMesh());
		const ARayProjectile* SpawnProjectile= GetWorld()->SpawnActor<ARayProjectile>(ProjectileType,RayProjectile->GetComponentTransform(), SpawnParameters);
		USphereComponent* CollisionSphere= Cast<USphereComponent>(SpawnProjectile->GetRootComponent());
		//FHitResult FireHit;
				
		//Ray Light projectile
		FVector FirstPlayerLocation=GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation(); //Player location in world
		FVector ForwardVector = GetActorForwardVector(); //Front location
		ForwardVector *= ImpulsePower;
						
		CollisionSphere->AddImpulse(ForwardVector,NAME_None, true );
	
	}

}
	
