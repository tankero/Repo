// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()


public:
	void Elevate(float DegreesPerSecond);

	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxElevation = 40.f;
	
	UPROPERTY(EditAnywhere, Category = Setup)
		float MinElevation = -20.f;

	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreesPerSecond = 20.f;

		
};
