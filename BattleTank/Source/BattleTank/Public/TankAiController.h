// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAiController.generated.h"

class ATank;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAiController : public AAIController
{
	GENERATED_BODY()

public:
		ATank* GetControlledTank() const;

		virtual void BeginPlay() override;
		virtual void Tick(float DeltaSeconds) override;
		ATank* GetPlayerControlledTank() const;
};
