// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "Tank.h"
#include "TankPlayerController.h"



void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }
	FoundAimingComponent(AimingComponent);
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrossHair();
}

void ATankPlayerController::OnPlayerDeath()
{
	StartSpectatingOnly();
}

void ATankPlayerController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)) { return; }

		// Subscribe our local method to the tank's death event
		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankPlayerController::OnPlayerDeath);
	}
}

void ATankPlayerController::AimTowardsCrossHair()
{
	if (!GetPawn()) { return; }
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }

	FVector OutHitLocation;
	
	if (GetSightRayHitLocation(OutHitLocation))
	{
		AimingComponent->AimAt(OutHitLocation);
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector &OutHitLocation) const
{
	int32 ViewPortX, ViewPortY;
	GetViewportSize(ViewPortX, ViewPortY);
	FVector LookDirection;
	auto ScreenLocation = FVector2D(ViewPortX * CrossHairLocationX, ViewPortY*CrossHairLocationY);
	if (GetPlayerRotation(ScreenLocation, LookDirection))
	{
		return GetLookVectorHitLocation(LookDirection, OutHitLocation);
	}
	return false;

}

bool ATankPlayerController::GetPlayerRotation(FVector2D ScreenLocation, FVector & WorldRotation) const
{
	FVector WorldLocation = FVector(1.0);
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocation, WorldRotation);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector &OutHitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto RayEnd = StartLocation + (LookDirection * RaySize);
	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, RayEnd, ECollisionChannel::ECC_Visibility))
	{
		OutHitLocation = HitResult.Location;
		return true;
	}
	OutHitLocation = FVector(0.0f);
	return false;
	
}
