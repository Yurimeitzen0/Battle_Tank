// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAiController.generated.h"


class UTankAimingComponent;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAiController : public AAIController
{
	GENERATED_BODY()

private:

		
		virtual void Tick(float DeltaSeconds) override;
protected:
	UPROPERTY(EditAnywhere, Category = "Setup")
	float AcceptanceRadius = 6000.0f;
};
