// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectTFG_U_v1/Enemy/MeleeEnemy.h"
#include "Kismet/GameplayStatics.h"


void AMeleeEnemy::MeleeAttack()
{
	FName SocketPlay;
	if(!Attack_Enemy_Montage) return;
	
	//Melee attack 
	SocketPlay=FName(TEXT("ComboAttack"));
	PlayMyAnimation(Attack_Enemy_Montage,1.0f, SocketPlay,0.0f,false);
}	