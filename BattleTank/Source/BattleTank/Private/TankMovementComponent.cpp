// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"
#include "TankMovementComponent.h"



void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
		LeftTrack = LeftTrackToSet;
		RightTrack = RightTrackToSet;
	
}


void UTankMovementComponent::IntendMoveForward(float Throw)
{
	
	if (!LeftTrack || !RightTrack){return;}
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
	//TODO fix/prevent double force
}

void UTankMovementComponent::IntendToTurn(float Throw)
{
	/*
	auto name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s speed: %f"), *name, Throw);
	*/
	if (!LeftTrack || !RightTrack){return;}
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
	//TODO fix/prevent double force
}

