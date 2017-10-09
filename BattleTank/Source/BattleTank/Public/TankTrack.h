// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
	
public:
	
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetThrottle(float Throttle);
	//Max Force per track in Newtons
	UPROPERTY(EditDefaultsOnly, Category = "TankTrack")
	float TrackMaxDrivingForce = 400000;
	UPROPERTY(EditDefaultsOnly, Category = "Physics")
	float InitialT = 0.5f;

private:
	UTankTrack();
	virtual void BeginPlay() override;
	void ApplySidewaysForce();
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);
	void DriveTrack();
	float CurrentThrottle = 0;
};
