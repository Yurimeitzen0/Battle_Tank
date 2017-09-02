// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // Must be the last include

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	
	ATank* GetControlledTank() const;

	void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
private:
	UPROPERTY(EditAnywhere)
	float CrossHairLocationX = 0.5f;
	UPROPERTY(EditAnywhere)
	float CrossHairLocationY = 0.3333f;
	UPROPERTY(EditAnywhere)
	float RaySize = 10000000.0f;
	void ATankPlayerController::AimTowardsCrossHair();
	bool GetSightRayHitLocation(FVector &OutHitLocation) const;
	bool GetPlayerRotation(FVector2D, FVector &) const;
	bool GetLookVectorHitLocation(FVector LookDirection,FVector &OutHitLocation) const;
};
