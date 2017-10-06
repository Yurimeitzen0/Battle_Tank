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
	UTankTrack();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction) override;
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetThrottle(float Throttle);
	//Max Force per track in Newtons
	UPROPERTY(EditDefaultsOnly, Category = "TankTrack")
	float TrackMaxDrivingForce = 400000;
	UPROPERTY(EditDefaultsOnly, Category = "Physics")
	float InitialT = 0.5f;
};
