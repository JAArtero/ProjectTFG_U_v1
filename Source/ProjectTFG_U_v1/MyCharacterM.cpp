// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacterM.h"

#include <chrono>

#include "ProjectTFG_U_v1/HUD/Blood_Code_UW.h"
#include "MeshAttributes.h"
#include "ProjectTFG_U_v1/Players/MyPlayerAAnimInstance.h"
#include "GameFramework/Character.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "Channels/MovieSceneChannelTraits.h"
#include "Engine/SkeletalMeshSocket.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/DamageType.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "ProjectTFG_U_v1/Components/MeleeHitInterface.h"
#include "ProjectTFG_U_v1GameModeBase.h"
<<<<<<< HEAD
#include "ProjectGameInstance.h"
#include "Components/SplineComponent.h"
=======
>>>>>>> parent of ed6d83c (Add GameInstance)


// Sets default values
AMyCharacterM::AMyCharacterM() :
BaseTurnRate(45.f), BaseLookUpRate(45.f) //Declaration
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	//My Camera 
	CameraBoom=CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength=400; //Distancia camara desde el personaje
	
	FollowCamera=CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);

    //Player rotate and walk direction
	CameraBoom->bUsePawnControlRotation= true; //Si gira 
	FollowCamera->bUsePawnControlRotation=false; //Indicamos si queremos que el personaje rote al rotar la camara (bool) 

	GetCharacterMovement()->bOrientRotationToMovement = true; 

    //Optional rotates player with the camera
	bUseControllerRotationYaw=false; 
	bUseControllerRotationPitch=false;
	bUseControllerRotationRoll=false;


	//Additional Movement Tips
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 360.0f, 0.0f);
	GetCharacterMovement()->JumpZVelocity = 600.0f;
	GetCharacterMovement()->AirControl = 0.5f;

	//Add Sword Weapon to Character
	KatanaInHand=CreateDefaultSubobject<USkeletalMeshComponent>(FName("KatanaInHandMesh"));
	KatanaInHand->SetupAttachment(GetMesh(), FName("KatanaInHandSocket"));
	KatanaInBack=CreateDefaultSubobject<USkeletalMeshComponent>(FName("KatanaBackMesh"));
	KatanaInBack->SetupAttachment(GetMesh(), FName("SwordBackSocket"));

	//Add Box Collision to Sword
	SwordCollision=CreateDefaultSubobject<UBoxComponent>(TEXT("Sword Collision Box"));
	SwordCollision->SetupAttachment(GetMesh(), FName("KatanaInHandSocket"));
	
	weaponSelectionKey=0;

	//Ray Particle
	RayProjectile = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Spot"));
	RayProjectile->SetupAttachment(RootComponent);
	
	//HUD
	PlayerHUDClass=nullptr;
	UIPlayerHUD=nullptr;
	
    //Stats
<<<<<<< HEAD
	//MagicRest=nullptrMagicForce/MAX_MAGICATTACK;

	MyGameInstance = Cast<UProjectGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	
=======
	MagicRest=MagicForce/MAX_MAGICATTACK;
>>>>>>> parent of ed6d83c (Add GameInstance)
}

// Called when the game starts or when spawned
void AMyCharacterM::BeginPlay()
{
	Super::BeginPlay();

	KatanaInBack->SetVisibility(false);

/*	
	//Restore values from Game Instant
	Health=MyGameInstance->GetPlayerHealth();
	MagicForce=MyGameInstance->GetPlayerMagicForce();
	MAX_MAGICATTACK=MyGameInstance->GetPlayerMax_Magicattack();
	MagicRest=MyGameInstance->GetPlayerMagicRest();
	//MagicRestoreVelocity=MyGameInstance->GetPlayerMagicRestoreVelocity();
	//HealthRestoreVelocity=MyGameInstance->GetPlayerHealthRestoreVelocity();
	CurrentLevel=MyGameInstance->GetPlayerCurrentLevel();
	bSwordIsActive=MyGameInstance->GetPlayerSwordIsActive();
	bMagicIsActive=MyGameInstance->GetPlayerMagicIsActive();
	MAX_Level=MyGameInstance->GetPlayerMax_Level();
	NextLevelPoints=MyGameInstance->GetPlayerNextLevelPoints();
*/	
	//Stats
	MagicRest=MagicForce/MAX_MAGICATTACK;
	
	//HUD Layer
	if(IsLocallyControlled() && PlayerHUDClass) // && !isDead)
	{
		APlayerController* FPC=GetController<APlayerController>();
		check(FPC);
		UIPlayerHUD=CreateWidget<UMyHUDWidget>(FPC, PlayerHUDClass);
		check(UIPlayerHUD);
		UIPlayerHUD->AddToPlayerScreen();
		UIPlayerHUD->SetHealth(Health, MAX_HEALTH);
		UIPlayerHUD->SetMagic(MagicForce,MAX_MagicForce);
		UIPlayerHUD->SetLevel(Points, MAX_Level, NextLevelPoints,0);
		UIPlayerHUD->SetLevelNumber(CurrentLevel);
<<<<<<< HEAD
		//AddScore(MyGameInstance->GetPlayerPoints());
		AddScore(0);
	}

	//if (Health<100) RestoreHealthLevel();
	//if (MagicForce<100) RestoreMagicLevel();
	
=======
		
		AddScore(0);
	}

>>>>>>> parent of ed6d83c (Add GameInstance)
	// Bind Function Overlap Sword
	SwordCollision->OnComponentBeginOverlap.AddDynamic(this, &AMyCharacterM::OnSwordOverlap);
	
	//Setup Sword Collision
	SwordCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	SwordCollision->SetCollisionObjectType(ECC_WorldDynamic);
	SwordCollision->SetCollisionResponseToChannels(ECR_Ignore);
	SwordCollision->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

    AGameModeBase* GameMode=UGameplayStatics::GetGameMode(GetWorld());
	AProjectTFG_U_v1GameModeBase* MyGameMode=Cast<AProjectTFG_U_v1GameModeBase>(GameMode);
	if(MyGameMode!=nullptr)
	{
		MyGameMode->AddScore.BindUObject(this, &AMyCharacterM::AddScore);
	}
}

//My  Binding
void AMyCharacterM::MoveForward(float Value)
{
	if(Controller!=nullptr && Value!=0.0f)
	{
		//Rotation
		const FRotator Rotation=Controller->GetControlRotation();
		const FRotator YawRotation(0,Rotation.Yaw,0); //Rotation in z (yaw)

		const FVector Direction=FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);//Vector direction
		AddMovementInput(Direction,Value);
	}
	
}

void AMyCharacterM::MoveRight(float Value)
{
	if(Controller!=nullptr && Value!=0.0f)
	{
		//Rotation
		const FRotator Rotation=Controller->GetControlRotation();
		const FRotator YawRotation(0,Rotation.Yaw,0); //Rotation in z (yaw)

		const FVector Direction=FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);//Vector direction
		AddMovementInput(Direction,Value);
		
	}
}

//Control Walk to Run 
void AMyCharacterM::RunStart()
{
	GetCharacterMovement()->MaxWalkSpeed=600.0f;
}

void AMyCharacterM::RunStop()
{
	GetCharacterMovement()->MaxWalkSpeed=300.0f;
}

void AMyCharacterM::TumbleStart()
{
	bIsTumble=true;
}

void AMyCharacterM::TumbleStop()
{
	bIsTumble=false;
}

//Pause Game
void AMyCharacterM::Pause()
{
		
	if(PauseMenuClass!=nullptr)
	{
		UPauseMenuUW* PauseWidget=CreateWidget<UPauseMenuUW>(GetWorld(), PauseMenuClass);
		if(PauseWidget!=nullptr)
		{
			APlayerController* FPC=GetController<APlayerController>();
			UGameplayStatics::PlaySound2D(this, SC_Open_Dialog);
			PauseWidget->AddToViewport();
			FPC->SetInputMode(FInputModeUIOnly());
			FPC->bShowMouseCursor=true;
			FPC->SetPause(true);
		}
	}
}


//Up and Down
void AMyCharacterM::TurnAtRate(float Rate)
{
	AddControllerYawInput(Rate*BaseTurnRate*GetWorld()->GetDeltaSeconds()); //Normalize velocity (frame rate)
}

void AMyCharacterM::LookAtRate(float Rate)
{
	AddControllerPitchInput(Rate*BaseLookUpRate*GetWorld()->GetDeltaSeconds());
}


// Called every frame
void AMyCharacterM::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//Ejecute Attack
void AMyCharacterM::Fire()
{	
	FName SocketPlay; 
	
	//Weapon 1
	if(weaponSelectionKey==1)
	{
		SocketPlay=FName(TEXT("Great_Atack_Sword"));
		PlayMyAnimation(Attack_Animation_Montage,1.0f, SocketPlay,0.0f,true);
	}

	//Weapon 2
	if(weaponSelectionKey==2 && MagicForce>0 && MagicForce>=MagicRest)
	{
		int32 SectionLength=0;
		SocketPlay=FName(TEXT("Magic_Large_Attack_Slot"));//Slot selected
		SectionLength=PlayMyAnimation(Attack_Animation_Montage,1.0f, SocketPlay,0.0f,true);

		//Delay to fire
		FTimerHandle TimerHandle;
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, [&]()
		{
			if(MyCameraShake)
			{
				UMatineeCameraShake::StartMatineeCameraShake(GetWorld()->GetFirstPlayerController()->PlayerCameraManager,
					MyCameraShake,
					1.0f,
					ECameraShakePlaySpace::CameraLocal,
					FRotator::ZeroRotator);
			}
			//Create Particles
		     FireLineCast("Fire_Socket");					
		}, 1.20, false);
		
		//Control Magic Force
		MagicForce=FMath::Clamp(MagicForce-MagicRest,0.0f, MAX_MagicForce);
		UpdateMagicForceBarHUD();
		RestoreMagicLevel();
	}
}

void AMyCharacterM::HardFire()
{
	FName SocketPlay=FName(TEXT("Super_Attack_Sword"));
	if(weaponSelectionKey==1)
	{
		//Hard animation to weapon 1
		PlayMyAnimation(Attack_Animation_Montage,1.0f, SocketPlay,0.0f,true);
		FTimerHandle TimerHandle;
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, [&]()
		{
			if(MyCameraShake)
			{
				UMatineeCameraShake::StartMatineeCameraShake(GetWorld()->GetFirstPlayerController()->PlayerCameraManager,
					MyCameraShake,
					1.0f,
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
			
			//Draw the radius of action for checks
			//DrawDebugSphere(GetWorld(), GetActorLocation(), ExplosionRadius, 16, FColor::Yellow, false, 5.0f,0 , 3.0f );
		}, 1.50, false);

	}
}


void AMyCharacterM::WeaponSelection1()
{
	//take the sword Animation
	if(bSwordIsActive)
	{
		if(weaponSelectionKey==0 || weaponSelectionKey==2 || weaponSelectionKey==3)
		{
			FName SheatheSword=FName(TEXT("SheatheSword"));
			PlayMyAnimation(Attack_Animation_Montage,1.9f, SheatheSword,0.0f,true);
			PlayMyAnimation(Attack_Animation_Montage,-1.9f, SheatheSword,0.0f, true);
			FTimerHandle TimerHandle;
			GetWorld()->GetTimerManager().SetTimer(TimerHandle, [&]()
			{
				KatanaInHand->SetVisibility(true);
				KatanaInBack->SetVisibility(false);
			}, 0.5, false);
		}
		weaponSelectionKey=1;
		UGameplayStatics::PlaySound2D(this, SC_Change_Weapon_Sound);
		UIPlayerHUD->SetImageWeapon(1);
	}
}

void AMyCharacterM::WeaponSelection2()
{
	//sheath the sword Animation
	int32 timeTMP;

	if(bMagicIsActive)
	{
		if(weaponSelectionKey==1)
		{
			FTimerHandle TimerHandle;
			FName SheatheSword=FName(TEXT("SheatheSword"));
			timeTMP=PlayMyAnimation(Attack_Animation_Montage,1.9f, SheatheSword,0.0f,true);
			GetWorld()->GetTimerManager().SetTimer(TimerHandle, [&]()
			{
				KatanaInHand->SetVisibility(false);
				KatanaInBack->SetVisibility(true);
			}, 0.5, false); //timeTMP, false);
			PlayMyAnimation(Attack_Animation_Montage,-1.9f, SheatheSword,0.0f,true);
		}
	
		weaponSelectionKey=2;
		UGameplayStatics::PlaySound2D(this, SC_Change_Weapon_Sound);
		UIPlayerHUD->SetImageWeapon(2);
	}
}

void AMyCharacterM::WeaponSelection3()
{
	weaponSelectionKey=3;
}

// Called to bind functionality to input
void AMyCharacterM::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this,&AMyCharacterM::MoveForward );
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyCharacterM::MoveRight);
	
	//Pause
	PlayerInputComponent->BindAction("Pause", IE_Pressed,this, &AMyCharacterM::Pause);
	
	//Up and Down
	PlayerInputComponent->BindAxis("TurnRate", this,&AMyCharacterM::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AMyCharacterM::LookAtRate);

	PlayerInputComponent->BindAction("Run", IE_Pressed, this, &AMyCharacterM::RunStart);
	PlayerInputComponent->BindAction("Run", IE_Released, this, &AMyCharacterM::RunStop);

	//Tumble
	PlayerInputComponent->BindAction("Tumble", IE_Pressed, this, &AMyCharacterM::TumbleStart);
	PlayerInputComponent->BindAction("Tumble", IE_Released, this, &AMyCharacterM::TumbleStop);

	//Camera  movement with mouse
	PlayerInputComponent->BindAxis("Turn", this,&APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	//Jump
	PlayerInputComponent->BindAction("Jump", IE_Pressed,this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this,&ACharacter::StopJumping);

	//Weapon
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AMyCharacterM::Fire);
	PlayerInputComponent->BindAction("HardFire", IE_Pressed, this, &AMyCharacterM::HardFire);

	PlayerInputComponent->BindAction("WeaponSelection1", IE_Pressed,this, &AMyCharacterM::WeaponSelection1);
	PlayerInputComponent->BindAction("WeaponSelection2", IE_Pressed,this, &AMyCharacterM::WeaponSelection2);
	PlayerInputComponent->BindAction("WeaponSelection3", IE_Pressed,this, &AMyCharacterM::WeaponSelection3);

}

void AMyCharacterM::ActivateSwordBoxCollision()
{
	SwordCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
}

void AMyCharacterM::DeactivateSwordBoxCollision()
{
	SwordCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

void AMyCharacterM::ViewDeathMenu()
{
	if(DeathMenuClass!=nullptr)
	{
		UDeathUW* DeathWidget=CreateWidget<UDeathUW>(GetWorld(), DeathMenuClass);
		if(DeathWidget!=nullptr)
		{	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red,FString::Printf(TEXT("Menu add")));

			APlayerController* FPC=GetController<APlayerController>();
			UGameplayStatics::PlaySound2D(this, SC_Open_Dialog);
			DeathWidget->AddToViewport();
			FPC->SetInputMode( FInputModeGameAndUI());// FInputModeUIOnly());
			FPC->bShowMouseCursor=true;
			//FPC->SetPause(true);
		}
	}

	
}

bool AMyCharacterM::SetActivateSword(bool ActiveSword)
{
	bSwordIsActive=ActiveSword;
	UGameplayStatics::PlaySound2D(this, SC_Change_Weapon_Sound);
	UIPlayerHUD->SetSwordAvailable(1);
	KatanaInBack->SetVisibility(true);

	return true;
	
}

bool AMyCharacterM::SetActiveMagic(bool ActiveMagic)
{
	bMagicIsActive=ActiveMagic;
	UGameplayStatics::PlaySound2D(this, SC_Change_Weapon_Sound);
	UIPlayerHUD->SetMagicAvailable(1);
	return true;

	
}

void AMyCharacterM::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp,
                              bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	//Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red,FString::Printf(TEXT("Notify Hit")));
/*
	if (Other)
	{
		float DamageAmount = 10.0f;
		FDamageEvent DamageEvent;
		DamageEvent.DamageTypeClass = UMyDamageType::StaticClass();
		DamageEvent.Damage = DamageAmount;
		Other->TakeDamage(DamageAmount, DamageEvent, GetInstigatorController(), this);
	}*/
}


void AMyCharacterM::OnSwordOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
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
	UGameplayStatics::ApplyDamage(SweepResult.GetActor(),BaseDamage, GetController(), this, UDamageType::StaticClass());
}

//Play Slot from AnimInstance 
int32 AMyCharacterM::PlayMyAnimation(UAnimMontage* MontageToPlay, float InPlayRate, FName SlotName , float InTimeToStartMontageAt, bool Delay)
{
	UAnimInstance* AnimInstance=GetMesh()->GetAnimInstance();
	int32 SectionLength=0;
	if(!AnimInstance->Montage_IsPlaying(MontageToPlay))
	{
		if(Delay){DisableMovement();} //GetCharacterMovement()->DisableMovement();}
		//Get Time it takes to Montage section
	    int32 SectionIndex=MontageToPlay->GetSectionIndex(SlotName);
		SectionLength=MontageToPlay->GetSectionLength(SectionIndex);

	   	AnimInstance->Montage_Play(MontageToPlay,InPlayRate, EMontagePlayReturnType::Duration, InTimeToStartMontageAt, true);	//Animation montage
		AnimInstance->Montage_JumpToSection(FName(SlotName));	//Slot selected
		GetWorldTimerManager().SetTimer(TimerMovement, this, &AMyCharacterM::EnableMovement, SectionLength);
	}
	return SectionLength;
}

//Pause o resume character movement 
void AMyCharacterM::DisableMovement()
{
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	DisableInput(PlayerController);

}

void AMyCharacterM::EnableMovement()
{
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	EnableInput(PlayerController);
	
}


//System of particles
void AMyCharacterM::FireLineCast(FName SocketName)
{
	//Create Fire Collision
	const USkeletalMeshSocket* Fire_Socket=GetMesh()->GetSocketByName(SocketName);
	//Create projectile
	const FActorSpawnParameters SpawnParameters;
	
		
	if(Fire_Socket)
	{
		const FTransform Fire_SocketTransform=Fire_Socket->GetSocketTransform(GetMesh());
		const ARayProjectile* SpawnProjectile= GetWorld()->SpawnActor<ARayProjectile>(ProjectileType, RayProjectile->GetComponentTransform(), SpawnParameters);

		//Ray Light projectile
		FVector ForwardVector = GetActorForwardVector();
		USphereComponent* Collision= Cast<USphereComponent>(SpawnProjectile->GetRootComponent());
		ForwardVector *= SpawnMult;

		//Fire Collision
		FHitResult FireHit;
		const FVector StartFire=Fire_SocketTransform.GetLocation();
		const FQuat RotationFire=Fire_SocketTransform.GetRotation();
		const FVector RotationFireAxis=RotationFire.GetAxisX();
		const FVector EndFire=(StartFire+RotationFireAxis*10000.f);
		GetWorld()->LineTraceSingleByChannel(FireHit, StartFire, EndFire, ECC_Visibility); //Calculate direction
		//DrawDebugLine(GetWorld(), StartFire, EndFire, FColor::Blue, false, 0.3f);
			
		if(FireHit.bBlockingHit && ImpactParticles)//Detecta si existe colisión para dibujar trayectoria e impacto, o no dibuja nada OJO
		{
			//DrawDebugPoint(GetWorld(),FireHit.ImpactPoint, 60, FColor:: Red, false, 2.f);
			Collision->AddImpulse(ForwardVector,NAME_None, true );
			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(),ImpactParticles,FireHit.ImpactPoint);
			auto actor=FireHit.GetActor();
			auto owner=GetOwner();
			UGameplayStatics::ApplyPointDamage(actor, BaseMagicDamage, FireHit.ImpactNormal, FireHit, GetInstigatorController(),owner, UDamageType::StaticClass());
			//UGameplayStatics::ApplyDamage(FireHit.GetActor(),DamagePoint, GetController(), this, UDamageType::StaticClass());
			
		}
	}
}

float AMyCharacterM::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator,
	AActor* DamageCauser)
{
	DisableMovement();
	bHitEvent=true;

	if(!isDead)
	{
		Health=FMath::Clamp(Health-DamageAmount,0.0f, MAX_HEALTH);
		UpdateHealtBarHUD(Health);
		if(Health<=0 || isDead)
		{
			UIPlayerHUD->RemoveFromParent();
			UIPlayerHUD=nullptr;
			isDead=true;
			//ViewDeathMenu();
			//OnDead();
			//EndPlay(EEndPlayReason::Destroyed);
			//Destroy();
		
		}
	
		//Create Blood Frame
		if(BloodWClass!=nullptr)
		{
			UBlood_Code_UW* BloodWidget=CreateWidget<UBlood_Code_UW>(GetWorld(), BloodWClass);
			if(BloodWidget!=nullptr)
			{
				BloodWidget->AddToViewport();
			}
		
		}
		RestoreHealthLevel();
	}
	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, [&]()
	{
		bHitEvent=false;
		EnableMovement();
	}, 1.0f, false);
	return DamageAmount;
}

void AMyCharacterM::OnDead()
{
	/*GetCharacterMovement()->StopMovementImmediately();
	auto world{GetWorld()};
	if(!world) return;
	auto Gmode{Cast<AProjectTFG_U_v1GameModeBase>(GetWorld()->GetAuthGameMode())};
	if(!Gmode) return;
	
	Gmode->RestartGameTimer();*/
	
	UnPossessed();
	//Destroy();	
}

void AMyCharacterM::CreateFireParticules(FString SocketName)
{
}

bool AMyCharacterM::Heal( float amount)
{
	if(Health>=MAX_HEALTH){return false;}

	Health=FMath::Clamp(Health+amount, 0.0f, MAX_HEALTH);
	if(!isDead)
	{
		UpdateHealtBarHUD(Health);
	}
	return true;
}


void AMyCharacterM::UpdateMagicForceBarHUD()
{
	if(!isDead)
	{
		UIPlayerHUD->SetMagic(MagicForce, MAX_MagicForce);
	}
}

void AMyCharacterM::UpdateHealtBarHUD(float LiveValue)
{
	if(!isDead)
	{
		UIPlayerHUD->SetHealth(LiveValue, MAX_HEALTH);
	}
}
void AMyCharacterM::UpdateLevelHUD(int Level, float PercentNumber, float NextLPoints)
{
	UIPlayerHUD->SetLevel(Points, MAX_Level,NextLPoints, PercentNumber);
	if(CurrentLevel!=Level){UIPlayerHUD->SetLevelNumber(Level);}
}

void AMyCharacterM::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if(PlayerCameraShake)
	{
		UIPlayerHUD->RemoveFromParent();
		UIPlayerHUD=nullptr;
	}
}

void AMyCharacterM::AddScore(float score)
{
	Points+=score;
   	
//update level based on current score
	if(Points>=0 && Points<100)
	{//Level 1
		UpdateLevelHUD(0,Points,100);
<<<<<<< HEAD
		MyGameInstance->SetPlayerCurrentLevel(0);
		MyGameInstance->SetPlayerNextLevelPoints(100);
=======
>>>>>>> parent of ed6d83c (Add GameInstance)
	}
	if(Points>=100 && Points<200)
	{//Level 2
		UpdateLevelHUD(1,Points-100,200);
<<<<<<< HEAD
		MyGameInstance->SetPlayerCurrentLevel(1);
		MyGameInstance->SetPlayerNextLevelPoints(200);

=======
>>>>>>> parent of ed6d83c (Add GameInstance)
	}
	if(Points>=200 && Points<300)
	{//Level 3
		UpdateLevelHUD(2,Points-200,300);
		MagicRestoreVelocity=0.8f;
<<<<<<< HEAD
		HealthRestoreVelocity=0.8f;
		MyGameInstance->SetPlayerCurrentLevel(2);
		MyGameInstance->SetPlayerNextLevelPoints(300);
		MyGameInstance->SetPlayerMagicRestoreVelocity(0.8);
		MyGameInstance->SetPlayerHealthRestoreVelocity(0.8);
=======
>>>>>>> parent of ed6d83c (Add GameInstance)
	}
	if(Points>=300 && Points<400)
	{//Level4
		UpdateLevelHUD(3,Points-300,400);
<<<<<<< HEAD
		MyGameInstance->SetPlayerCurrentLevel(3);
		MyGameInstance->SetPlayerNextLevelPoints(400);

=======
>>>>>>> parent of ed6d83c (Add GameInstance)
	}
	if(Points>=400 && Points<=500)
	{//Level 5
		UpdateLevelHUD(4,Points-100,500);
		MagicRestoreVelocity=0.6f;
<<<<<<< HEAD
		MyGameInstance->SetPlayerCurrentLevel(4);
		MyGameInstance->SetPlayerNextLevelPoints(500);
		MyGameInstance->SetPlayerMagicRestoreVelocity(0.6);
=======
>>>>>>> parent of ed6d83c (Add GameInstance)
	}
	if(Points>=500)
	{
		MagicRestoreVelocity=0.5f;
		HealthRestoreVelocity=0.6f;
<<<<<<< HEAD
		MyGameInstance->SetPlayerCurrentLevel(5);
		MyGameInstance->SetPlayerNextLevelPoints(500);
		MyGameInstance->SetPlayerHealthRestoreVelocity(0.6);
=======
>>>>>>> parent of ed6d83c (Add GameInstance)
	}
	
}

//Restores Magic at the rate specified by MagicRestoreVelocity
void AMyCharacterM::RestoreMagicLevel()
{
	if(!isDead)
	{
		FTimerHandle TimerHandle;
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, [&]()
		{
			MagicForce=FMath::Clamp(MagicForce+0.1f,0.0, MAX_MagicForce);
			UpdateMagicForceBarHUD();
			 if(MagicForce==MAX_MagicForce){return;};
		}, MagicRestoreVelocity, true);
	}
}

//restores health at the rate specified by HealtRestoreVelocity
void AMyCharacterM::RestoreHealthLevel()
{
	if(!isDead)
	{
		FTimerHandle TimerHandle;
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, [&]()
		{
			Health=Health+0.1f;
			UpdateHealtBarHUD(Health);
			if(Health==MAX_HEALTH){return;};
		}, HealthRestoreVelocity, true);
	}
}
