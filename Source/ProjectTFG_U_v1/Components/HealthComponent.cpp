
#include "ProjectTFG_U_v1/Components/HealthComponent.h"
#include "ProjectTFG_U_v1/HUD/HealthBar.h"
#include "GameFramework/PlayerController.h"


//#include "ProjectTFG_U_v1/MyCharacterM.h"
//#include "ProjectTFG_U_v1/MyCharacterM.h"
#include "Kismet/GameplayStatics.h"
#include "ProjectTFG_U_v1/ProjectTFG_U_v1GameModeBase.h"
//#include "ProjectTFG_U_v1/Enemy/Enemy.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	auto owner=GetOwner();
	if(!owner) return;

	owner->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::OnOwnerDamage);

	
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}


//Up Live
bool UHealthComponent::Heal( float amount)
{
if(ActualLife>=MAX_LIFE){return false;}

	ActualLife=FMath::Clamp(ActualLife+amount, 0.0f, MAX_LIFE);
	return true;
}



//Damage to the owner
void UHealthComponent::OnOwnerDamage(AActor* DamagedActor,float Damage,const class UDamageType* DamageType,class AController* InstigatedBy,AActor* DamageCauser)
{
	if(!GetOwner()) return;
	if(bDie) return;
	
	OnDamage.Broadcast(ActualLife);
	ActualLife=FMath::Clamp(ActualLife-Damage,0.0f, MAX_LIFE);
	
		
	/*AGameModeBase* GameMode=UGameplayStatics::GetGameMode(GetWorld());
	AProjectTFG_U_v1GameModeBase* MyGameMode=Cast<AProjectTFG_U_v1GameModeBase>(GameMode);
	if(MyGameMode!=nullptr)
	{
		MyGameMode->AddScore.ExecuteIfBound(100.f); 
	}*/
	
	if(ActualLife<=0.0f)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red,FString::Printf(TEXT("Estas Muerto")));

		//Destroy Owner and childrens
		//auto owner=GetOwner();
		//if(!owner) return;
		//owner->Destroy();
		
		OnDead.Broadcast(DamagedActor, Damage, DamageType, InstigatedBy, DamageCauser);
		bDie=true;
	}
}

void UHealthComponent::UpdateHealth(float HealthDelta)
{
	
	
}

void UHealthComponent::MeleeHit_Implementation(FHitResult HitResult)
{
	//IMeleeHitInterface::MeleeHit_Implementation(HitResult);
	/*AGameModeBase* GameMode=UGameplayStatics::GetGameMode(GetWorld());
	AProjectTFG_U_v1GameModeBase* MyGameMode=Cast<AProjectTFG_U_v1GameModeBase>(GameMode);
	if(MyGameMode!=nullptr)
	{
		MyGameMode->AddScore.ExecuteIfBound(200.f); 
	}*/
}

float UHealthComponent::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator,AActor* DamageCauser)
{
	if(ActualLife-DamageAmount<=0.f)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red,FString::Printf(TEXT(" Muerto Muerto")));
	}
	else
	{  
		ActualLife=FMath::Clamp(ActualLife-DamageAmount,0.0f, MAX_LIFE);
		//OnDamage.Broadcast(ActualLife);
		
		
	/*	AGameModeBase* GameMode=UGameplayStatics::GetGameMode(GetWorld());
		AProjectTFG_U_v1GameModeBase* MyGameMode=Cast<AProjectTFG_U_v1GameModeBase>(GameMode);
		if(MyGameMode!=nullptr)
		{
			MyGameMode->AddScore.ExecuteIfBound(300.f);
		}*/
	}

	return DamageAmount;
}

