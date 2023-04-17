//***********************************************************************************************
//************************** Animation My Player Character A **************************************
//***********************************************************************************************

#include "ProjectTFG_U_v1/Players/MyPlayerAAnimInstance.h"
#include "ProjectTFG_U_v1/Players/MyCharacterA.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetArrayLibrary.h"
#include "Kismet/KismetMathLibrary.h"


void UMyPlayerAAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	//Super::NativeUpdateAnimation(DeltaSeconds);
	PlayerCharacterA=Cast<AMyCharacterA>(TryGetPawnOwner());
}


void UMyPlayerAAnimInstance::NativeUpdateAnimation(float DeltaSeconds)  //UpdateAnimationProperty(float Deltatime)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if(PlayerCharacterA==nullptr)
	{
		PlayerCharacterA=Cast<AMyCharacterA>(TryGetPawnOwner());
	}
	else
	{
		//Add Velocity to speed 
		FVector Velocity=PlayerCharacterA->GetVelocity();
		Velocity.Z=0;
		Speed=Velocity.Size();

		//Is in Air?
		bIsInAir=PlayerCharacterA->GetCharacterMovement()->IsFalling();

		//Running?
		/*if(PlayerCharacterA->GetCharacterMovement()->GetCurrentAcceleration().Size()>0.0f)
		{
			bIsAccelerating=true;
		}else
		{
			bIsAccelerating=false;
		}*/
		bIsAccelerating=(PlayerCharacterA->GetCharacterMovement()->GetCurrentAcceleration().Size()>0.0f);

		FRotator AimRotation=PlayerCharacterA->GetBaseAimRotation();
		FRotator MovementRotation=UKismetMathLibrary::MakeRotFromX(PlayerCharacterA->GetVelocity());

        //combine two rotations for create one direction oblique
		MovementOffsetYaw=UKismetMathLibrary::NormalizedDeltaRotator(AimRotation, MovementRotation).Roll;

		if(PlayerCharacterA->GetVelocity().Size()>0)
		{
			LastMovementOffsetYaw=MovementOffsetYaw;
		}
	}
}
