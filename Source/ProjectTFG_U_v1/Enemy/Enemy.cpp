


#include "ProjectTFG_U_v1/Enemy/Enemy.h"

#include "ProjectTFG_U_v1/Components/HealthComponent.h"
#include "MatineeCameraShake.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "ProjectTFG_U_v1/AI/EnemyAIController.h"
#include "ProjectTFG_U_v1/HUD/HealthBar.h"
#include "ProjectTFG_U_v1/ProjectTFG_U_v1GameModeBase.h"


// Sets default values
AEnemy::AEnemy()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Health component 
	Health=CreateDefaultSubobject<UHealthComponent>(FName("HealthComponent"));
	
	//AI Component
	AutoPossessAI=EAutoPossessAI::PlacedInWorldOrSpawned;
	AIControllerClass=AEnemyAIController::StaticClass();
}
// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	if(!Health)
	{
		return;
	}

	Health->OnDead.AddDynamic(this, &AEnemy::OnDead);
	Health->OnDamage.AddDynamic(this, &AEnemy::OnDamage);
}

void AEnemy::DisableMovement()
{
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	DisableInput(PlayerController);
}

void AEnemy::EnableMovement()
{
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	EnableInput(PlayerController);
}

void AEnemy::UpdateScore(float points)
{
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AEnemy::OnDead(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigateBy,
                    AActor* DamageCauser)
{
	//Wait time for destruction
	SetLifeSpan(10.0f);
	DetachFromControllerPendingDestroy();
	GetCharacterMovement()->StopMovementImmediately();
}

void AEnemy::OnDamage(float ActualLife)
{
	//GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Blue,FString::Printf(TEXT("OnDamage Enemy")));
	PlayAnimMontage(DamageAnimation);
	AGameModeBase* GameMode=UGameplayStatics::GetGameMode(GetWorld());
	AProjectTFG_U_v1GameModeBase* MyGameMode=Cast<AProjectTFG_U_v1GameModeBase>(GameMode);
	if(MyGameMode!=nullptr)
	{
			MyGameMode->AddScore.ExecuteIfBound(BaseApplyScoreMelee);
	}
}

int32 AEnemy::PlayMyAnimation(UAnimMontage* MontageToPlay, float InPlayRate, FName SlotName , float InTimeToStartMontageAt, bool Delay)
{
	UAnimInstance* AnimInstance=GetMesh()->GetAnimInstance();
	int32 SectionLength=0;
	if(!AnimInstance->Montage_IsPlaying(MontageToPlay))
	{
		if(Delay){DisableMovement();}
		
		//Get Time it takes to Montage section
		int32 SectionIndex=MontageToPlay->GetSectionIndex(SlotName);
		SectionLength=MontageToPlay->GetSectionLength(SectionIndex);

		AnimInstance->Montage_Play(MontageToPlay,InPlayRate, EMontagePlayReturnType::Duration, InTimeToStartMontageAt, true);	//Animation montage
		AnimInstance->Montage_JumpToSection(FName(SlotName));	//Slot selected
		GetWorldTimerManager().SetTimer(TimerMovement, this, &AEnemy::EnableMovement, SectionLength);
	}
	return SectionLength;
}

