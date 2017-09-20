// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"
#include "TankMovementComponent.h"



void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	if (!LeftTrackToSet || !RightTrackToSet)
	{
		return;
	}
	else
	{
		LeftTrack = LeftTrackToSet;
		RightTrack = RightTrackToSet;
	}
	
}


void UTankMovementComponent::IntendMoveForward(float Throw)
{
	auto name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s speed: %f"), *name, Throw);

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
	//TODO fix/prevent double force
}
