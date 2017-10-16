// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // Put new includes above


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegate);

class AProjectile;
UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()
public:
		
	UFUNCTION(BlueprintPure,Category = "Health")
	float GetHealthPercent() const;
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser);
	FTankDelegate OnDeath;
	
private:

	virtual void BeginPlay() override;

	ATank();

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int32 MaxHealth = 200;

	UPROPERTY(VisibleAnywhere, Category = "Setup")
	int32 CurrentHealth;

};