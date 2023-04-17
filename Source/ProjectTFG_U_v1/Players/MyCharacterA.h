// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectTFG_U_v1/Components/MeleeHitInterface.h"
#include "GameFramework/Character.h"
#include "Sound/SoundCue.h"

//#include "InputActionValue.h"

//Ojo al final de los includes
#include "MyCharacterA.generated.h"

UCLASS()
class PROJECTTFG_U_V1_API AMyCharacterA : public ACharacter, public IMeleeHitInterface
{
	GENERATED_BODY()

	

private:
	//Add my movement objects functions declarations
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera, meta=(AllowPrivateAccess="true"))
	class USpringArmComponent* CameraBoom;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera, meta=(AllowPrivateAccess="true"))
	class UCameraComponent* FollowCamera;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera, meta=(AllowPrivateAccess="true"))
	float  BaseTurnRate;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera, meta=(AllowPrivateAccess="true"))
	float BaseLookUpRate;

	//Amrs
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Sound, meta=(AllowPrivateAccess="true"))
	USoundCue* FireLaserSound;

	//Animations
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Atack_Animation, meta=(AllowPrivateAccess="true"))
	UAnimMontage* Sword_Atack_L;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Combat", meta=(AllowPrivateAccess="true"))
	float Health;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Combat", meta=(AllowPrivateAccess="true"))
	float MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Atack_Animation, meta=(AllowPrivateAccess="true"))
	float BaseDamage;

	
public:
	// Sets default values for this character's properties
	AMyCharacterA();

	

protected:
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//My controller Bindings
	void MoveForward(float Value);
	void MoveRight(float Value);
	void TurnAtRate(float Rate);
	void LookAtRate(float Rate);
	// Arms
	void Fire();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator,	AActor* DamageCauser) override;


};
