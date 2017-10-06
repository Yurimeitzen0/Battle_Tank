// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"

UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankTrack::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{

	UE_LOG(LogTemp, Warning, TEXT("tick"));
	
	
	auto SlippageSpeed = FVector::DotProduct(GetComponentVelocity(), GetRightVector());
	auto AccelerationCorrection = -SlippageSpeed / DeltaTime * GetRightVector();
	auto CorrectionRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = (CorrectionRoot->GetMass() * AccelerationCorrection)/2;
	CorrectionRoot->AddForce(CorrectionForce*InitialT);
	
}
void UTankTrack::SetThrottle(float Throttle)
{
	//auto Time = GetWorld()->GetTimeSeconds();
	

	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}
