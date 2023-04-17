///***********************************************************************************************
//************************** Animation My Player Character M **************************************
//***********************************************************************************************

#include "MyPlayerMAnimInstance.h"
#include "MyCharacterM.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetArrayLibrary.h"
#include "Kismet/KismetMathLibrary.h"


void UMyPlayerMAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	//Super::NativeUpdateAnimation(DeltaSeconds);
	PlayerCharacterM=Cast<AMyCharacterM>(TryGetPawnOwner());
}


void UMyPlayerMAnimInstance::NativeUpdateAnimation(float DeltaSeconds)  
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if(PlayerCharacterM==nullptr)
	{
		PlayerCharacterM=Cast<AMyCharacterM>(TryGetPawnOwner());
	}
	else
	{
		//Add Velocity to speed 
		FVector Velocity=PlayerCharacterM->GetVelocity();
		Velocity.Z=0;
		Speed=Velocity.Size();

		//Is in Air?
		bIsInAir=PlayerCharacterM->GetCharacterMovement()->IsFalling();

		//Running?
		bIsAccelerating=(PlayerCharacterM->GetCharacterMovement()->GetCurrentAcceleration().Size()>0.0f);

		FRotator AimRotation=PlayerCharacterM->GetBaseAimRotation();
		FRotator MovementRotation=UKismetMathLibrary::MakeRotFromX(PlayerCharacterM->GetVelocity());

		//combine two rotations for create one direction oblique
		MovementOffsetYaw=UKismetMathLibrary::NormalizedDeltaRotator(AimRotation, MovementRotation).Roll;

		if(PlayerCharacterM->GetVelocity().Size()>0)
		{
			LastMovementOffsetYaw=MovementOffsetYaw;
		}
		Weapon_Selected=PlayerCharacterM->GetWeaponSelected();
		bIsTumble=PlayerCharacterM->GetIsTumble();
	
	}
}
