// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectTFG_U_v1/Components/MyMatineeCameraShake.h"

UMyMatineeCameraShake::UMyMatineeCameraShake()
{
	OscillationDuration=0.125f; //Duration
	OscillationBlendInTime=0.025f; //Inicio
	OscillationBlendOutTime=0.025f;//End

	//Pitch 
	RotOscillation.Pitch.Amplitude=FMath::RandRange(0.625f,2.0f); //Random Oscilation Range
	RotOscillation.Pitch.Frequency=FMath::RandRange(3.125f,4.375f); //Random Frecuency Range

	//Yaw Z
	RotOscillation.Yaw.Amplitude=FMath::RandRange(0.625f,2.0f); //Random Oscilation Range
	RotOscillation.Yaw.Frequency=FMath::RandRange(3.125f,4.375f); //Random Frecuency Range
	
}
