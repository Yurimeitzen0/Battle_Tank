// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAiController.h"

ATank* ATankAiController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankAiController::BeginPlay()
{
	Super::BeginPlay();
	// auto ControlledTank = GetControlledTank();
	//UE_LOG(LogTemp, Warning, TEXT("AiController set"));

	if (GetControlledTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("Got Ai Controlled Tank: %s"), *GetControlledTank()->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to get the Ai controlled tank"));
	}
}
