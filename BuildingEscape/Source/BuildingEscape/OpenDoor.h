// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "Components/ActorComponent.h"
#include "Curves/CurveFloat.h"
#include "OpenDoor.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorRequest);



UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))


class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UOpenDoor();

	UFUNCTION(BlueprintGetter)
		float GetOpenAngle();

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Open Angle Setting")
		float OpenAngle = 0.f;

	UFUNCTION(BlueprintGetter)
		float GetClosedAngle();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Closed Angle for Door")
		float ClosedAngle = 0.f;

	UPROPERTY(BlueprintAssignable)
		FDoorRequest OnClosed;

	UPROPERTY(BlueprintAssignable)
		FDoorRequest OnOpen;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


private:


	UPROPERTY(EditAnywhere)
		ATriggerVolume* PressurePlate = nullptr;

	UPROPERTY(VisibleAnywhere)
		bool bOpened = false;

	UPROPERTY(EditAnywhere)
		float TriggerMass = 50.f;

	

	AActor* Owner;
	FString OwnerName;

	float GetTotalMassOfActorsOnPlate() const;
};
