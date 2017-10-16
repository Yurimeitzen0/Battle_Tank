// Fill outyour copyright notice in the Description page of Project Settings.

#pragma once


#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // Must be the last include


class UTankAimingComponent;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimingComponent* AimingCompRef);

	
private:
	void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	virtual void SetPawn(APawn* InPawn) override;
	UFUNCTION()
	void OnPlayerDeath();

	UPROPERTY(EditDefaultsOnly)
	float CrossHairLocationX = 0.5f;
	
	UPROPERTY(EditDefaultsOnly)
	float CrossHairLocationY = 0.3333f;
	
	UPROPERTY(EditDefaultsOnly)
	float RaySize = 10000000.0f;
	
	void ATankPlayerController::AimTowardsCrossHair();
	bool GetSightRayHitLocation(FVector &OutHitLocation) const;
	bool GetPlayerRotation(FVector2D, FVector &) const;
	bool GetLookVectorHitLocation(FVector LookDirection,FVector &OutHitLocation) const;

};
