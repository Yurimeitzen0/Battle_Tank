// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "TankAiController.h"

void ATankAiController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	auto AiTank = (GetPawn());
	if (!ensure(AiTank)) { return; }
	auto PlayerTank = (GetWorld()->GetFirstPlayerController()->GetPawn());
	if (!ensure(PlayerTank ))	{return;}

	MoveToActor(PlayerTank, AcceptanceRadius);
	auto AimingComponent = AiTank->FindComponentByClass<UTankAimingComponent>();
	AimingComponent->AimAt(PlayerTank->GetActorLocation());
	AimingComponent->Fire();
	
	
	
	
}