// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectTFG_U_v1/Components/EnemyMatineeCameraShake.h"

UEnemyMatineeCameraShake::UEnemyMatineeCameraShake()
{
	OscillationDuration=0.40f; //Duration
	OscillationBlendInTime=0.05f; //Inicio
	OscillationBlendOutTime=0.05f;//End

	//Pitch 
	RotOscillation.Pitch.Amplitude=FMath::RandRange(3.625f,5.0f); //Random Oscilation Range
	RotOscillation.Pitch.Frequency=FMath::RandRange(3.125f,6.375f); //Random Frecuency Range

	//Yaw Z
	RotOscillation.Yaw.Amplitude=FMath::RandRange(1.625f,2.0f); //Random Oscilation Range
	RotOscillation.Yaw.Frequency=FMath::RandRange(3.125f,4.375f); //Random Frecuency Range
	
}
