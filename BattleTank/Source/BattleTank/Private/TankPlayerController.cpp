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
