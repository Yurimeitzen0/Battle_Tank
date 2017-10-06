// Frigid Coffin Ltd.

#include "BattleTank.h"
#include "TankTrack.h"
#include "TankMovementComponent.h"



void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
		LeftTrack = LeftTrackToSet;
		RightTrack = RightTrackToSet;
	
}


void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	auto TankFoward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIFowardVector = MoveVelocity.GetSafeNormal();
	auto FowardThrow = FVector::DotProduct(TankFoward, AIFowardVector);
	auto TurnThrow = FVector::CrossProduct(TankFoward, AIFowardVector);

	IntendMoveForward(FowardThrow);
	IntendToTurn(TurnThrow.Z);
	
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	
	if (!ensure(LeftTrack && RightTrack)){return;}
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
	//TODO fix/prevent double force
}

void UTankMovementComponent::IntendToTurn(float Throw)
{
	/*
	auto name = GetName();
	
	*/
	if (!ensure(LeftTrack && RightTrack)) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
	//TODO fix/prevent double force
}

