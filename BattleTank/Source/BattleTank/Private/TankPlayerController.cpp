// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	// auto ControlledTank = GetControlledTank();
	//UE_LOG(LogTemp, Warning, TEXT("PlayerController set"));
	
	if (GetControlledTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("Got Controlled Tank: %s"), *GetControlledTank()->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to get the controlled tank"));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//UE_LOG(LogTemp, Warning, TEXT("Tick Working properly"));
	AimTowardsCrossHair();
}

void ATankPlayerController::AimTowardsCrossHair()
{
	if (!GetControlledTank())
	{
		return;
	}
	FVector OutHitLocation;
	
	if (GetSightRayHitLocation(OutHitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *OutHitLocation.ToString());
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
		GetLookVectorHitLocation(LookDirection, OutHitLocation);
		
		//UE_LOG(LogTemp, Warning, TEXT("Look Direction(vector) : %s"), *WorldRotation.ToString())
	}
	return true;

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
