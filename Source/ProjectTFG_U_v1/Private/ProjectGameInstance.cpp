// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectGameInstance.h"



UProjectGameInstance::UProjectGameInstance()
{	

}

void UProjectGameInstance::Init()
{
	Super::Init();

	PlayerHealth=0; //50.0;
	PlayerMaxHealth=0;//100.0;
	PlayerMagicForce=0;//30.0;
	PlayerMaxMagicForce=0;//100.0f;
	PlayerMAX_MAGICATTACK=0;//4.0f;
	PlayerMagicRest=0;//.0f;
	PlayerPoints=0;//101.0f;	
	PlayerMAX_Level=0;//100.0f;
	PlayerbSwordIsActive=false;
	PlayerbMagicIsActive=false;
	
	//PlayerMagicRestoreVelocity=0.2f;  //1.0 ?????Necesario
	//PlayerHealthRestoreVelocity=0.2f;  //1.0   NBecesario???
	//PlayerCurrentLevel=0;  //Necesario???
	//PlayerNextLevelPoints=100.0f;  //Necesario??

	
}

//Getters and Setters

float UProjectGameInstance::GetPlayerHealth() 
{
	return PlayerHealth;
}

void UProjectGameInstance::SetPlayerHealth(float Health) 
{
	this->PlayerHealth = Health;
}

float UProjectGameInstance::GetPlayerMaxHealth() 
{
	return PlayerMaxHealth;
}

void UProjectGameInstance::SetPlayerMaxHealth(float Health) 
{
	this->PlayerMaxHealth = Health;
}


float UProjectGameInstance::GetPlayerMagicForce() 
{
	return PlayerMagicForce;
}

void UProjectGameInstance::SetPlayerMagicForce(float MagicForce)
{
	this->PlayerMagicForce = MagicForce;
}

float UProjectGameInstance::GetPlayerMaxMagicForce() 
{
	return PlayerMaxMagicForce;
}

void UProjectGameInstance::SetPlayerMaxMagicForce(float MaxMagicForce)
{
	this->PlayerMaxMagicForce = MaxMagicForce;
}

float UProjectGameInstance::GetPlayerMax_Magicattack() 
{
	return PlayerMAX_MAGICATTACK;
}

void UProjectGameInstance::SetPlayerMax_Magicattack(float Max_Magicattack)
{
	this->PlayerMAX_MAGICATTACK = Max_Magicattack;
}

float UProjectGameInstance::GetPlayerMagicRest() 
{
	return PlayerMagicRest;
}

void UProjectGameInstance::SetPlayerMagicRest(float MagicRest) 
{
	this->PlayerMagicRest = MagicRest;
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
	this->PlayerCurrentLevel = CurrentLevel;
}

bool UProjectGameInstance::GetPlayerSwordIsActive() 
{
	return PlayerbSwordIsActive;
}

void UProjectGameInstance::SetPlayerSwordIsActive(bool bSwordIsActive)
{
	this->PlayerbSwordIsActive = bSwordIsActive;
}

bool UProjectGameInstance::GetPlayerMagicIsActive() 
{
	return PlayerbMagicIsActive;
}

void UProjectGameInstance::SetPlayerMagicIsActive(bool bMagicIsActive)
{
	this->PlayerbMagicIsActive = bMagicIsActive;
}


float UProjectGameInstance::GetPlayerMax_Level() 
{
	return PlayerMAX_Level;
}

void UProjectGameInstance::SetPlayerMax_Level(float Max_Level)
{
	this->PlayerMAX_Level = Max_Level;
}

float UProjectGameInstance::GetPlayerNextLevelPoints() 
{
	return PlayerNextLevelPoints;
}

void UProjectGameInstance::SetPlayerNextLevelPoints(float NextLevelPoints)
{
	this->PlayerNextLevelPoints = NextLevelPoints;
}


