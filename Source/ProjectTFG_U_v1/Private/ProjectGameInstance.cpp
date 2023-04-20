// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectGameInstance.h"



float UProjectGameInstance::GetPlayerHealth() 
{
	return PlayerHealth;
}

void UProjectGameInstance::SetPlayerHealth(float Health) 
{
	PlayerHealth = Health;
}

float UProjectGameInstance::GetPlayerMagicForce() 
{
	return PlayerMagicForce;
}

void UProjectGameInstance::SetPlayerMagicForce(float MagicForce)
{
	this->PlayerMagicForce = MagicForce;
}

float UProjectGameInstance::GetPlayerMax_Magicattack() 
{
	return PlayerMAX_MAGICATTACK;
}

void UProjectGameInstance::SetPlayerMax_Magicattack(float Max_Magicattack)
{
	PlayerMAX_MAGICATTACK = Max_Magicattack;
}

float UProjectGameInstance::GetPlayerMagicRest() 
{
	return PlayerMagicRest;
}

void UProjectGameInstance::SetPlayerMagicRest(float MagicRest) 
{
	PlayerMagicRest = MagicRest;
}

float UProjectGameInstance::GetPlayerMagicRestoreVelocity() 
{
	return PlayerMagicRestoreVelocity;
}

void UProjectGameInstance::SetPlayerMagicRestoreVelocity(float MagicRestoreVelocity)
{
	this->PlayerMagicRestoreVelocity = MagicRestoreVelocity;
}

float UProjectGameInstance::GetPlayerHealthRestoreVelocity() 
{
	return PlayerHealthRestoreVelocity;
}

void UProjectGameInstance::SetPlayerHealthRestoreVelocity(float HealthRestoreVelocity)
{
	this->PlayerHealthRestoreVelocity = HealthRestoreVelocity;
}

float UProjectGameInstance::GetPlayerPoints() 
{
	return PlayerPoints;
}

void UProjectGameInstance::SetPlayerPoints(float Points)
{
	this->PlayerPoints = Points;
}

int UProjectGameInstance::GetPlayerCurrentLevel() 
{
	return PlayerCurrentLevel;
}

void UProjectGameInstance::SetPlayerCurrentLevel(int CurrentLevel)
{
	PlayerCurrentLevel = CurrentLevel;
}

bool UProjectGameInstance::GetPlayerSwordIsActive() const
{
	return PlayerbSwordIsActive;
}

void UProjectGameInstance::SetPlayerSwordIsActive(bool bSwordIsActive)
{
	this->PlayerbSwordIsActive = bSwordIsActive;
}

bool UProjectGameInstance::GetPlayerMagicIsActive() const
{
	return PlayerbMagicIsActive;
}

void UProjectGameInstance::SetPlayerMagicIsActive(bool bMagicIsActive)
{
	this->PlayerbMagicIsActive = bMagicIsActive;
}
