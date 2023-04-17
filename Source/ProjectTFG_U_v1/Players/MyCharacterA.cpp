// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectTFG_U_v1/Players/MyCharacterA.h"
#include "GameFramework/Character.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AMyCharacterA::AMyCharacterA() :
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

	GetCharacterMovement()->bOrientRotationToMovement = true; //??????

    //Optional rotates player with the camera
	bUseControllerRotationYaw=false; //z
	bUseControllerRotationPitch=false;//Y?
	bUseControllerRotationRoll=false;


	//Additional Movement Tips
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 360.0f, 0.0f);
	GetCharacterMovement()->JumpZVelocity = 600.0f;
	GetCharacterMovement()->AirControl = 0.2f;
	
	
}
// Called when the game starts or when spawned
void AMyCharacterA::BeginPlay()
{
	Super::BeginPlay();

}

//My  Binding
void AMyCharacterA::MoveForward(float Value)
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

void AMyCharacterA::MoveRight(float Value)
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
//Up and Down
void AMyCharacterA::TurnAtRate(float Rate)
{
	AddControllerYawInput(Rate*BaseTurnRate*GetWorld()->GetDeltaSeconds()); //Normalize velocity (frame rate)
}

void AMyCharacterA::LookAtRate(float Rate)
{
	AddControllerPitchInput(Rate*BaseLookUpRate*GetWorld()->GetDeltaSeconds());
}



void AMyCharacterA::Fire()
{
	if(FireLaserSound)
	{
		UGameplayStatics::PlaySound2D(this, FireLaserSound);
	}
	//Change animation to fire
	UAnimInstance* AnimInstance=GetMesh()->GetAnimInstance();
	if(AnimInstance && Sword_Atack_L)
	{
        AnimInstance->Montage_Play(Sword_Atack_L);
		AnimInstance->Montage_JumpToSection(FName("SwordAtackL"));
		
		
	}
	
}


// Called every frame
void AMyCharacterA::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacterA::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this,&AMyCharacterA::MoveForward );
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyCharacterA::MoveRight);

	//Up and Down
	//PlayerInputComponent->BindAxis("TurnRate", this,&AMyCharacterA::TurnAtRate);
	//PlayerInputComponent->BindAxis("LookUpRate", this, &AMyCharacterA::LookAtRate);

	//Camera  movement with mouse
	PlayerInputComponent->BindAxis("Turn", this,&APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	//Jump
	PlayerInputComponent->BindAction("Jump", IE_Pressed,this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this,&ACharacter::StopJumping);


	//Arms
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AMyCharacterA::Fire);

}

float AMyCharacterA::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator,
	AActor* DamageCauser)
{
	//return Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	if (Health-DamageAmount<=0.f)
	{
		
	}
	else
	{
		Health-=DamageAmount;
	}
	return DamageAmount;
}





