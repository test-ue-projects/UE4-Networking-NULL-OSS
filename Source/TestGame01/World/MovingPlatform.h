// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class TESTGAME01_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()

	AMovingPlatform();

	protected:
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;

	//if active trigger is > 0 , then the platform  moves. By adding or removing actove trigger counter we can switch platform movement 
	UPROPERTY(EditAnywhere)
	int ActiveTriggers = 1;		 

	public:
	UPROPERTY(EditAnywhere, Category = "Params")
	float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Params", Meta = (MakeEditWidget = true))
	FVector TargetLocation;

	FVector GlobalStartLocataion;
	FVector GlobalTargetLocation;
	
	FVector TempGlobalStartLocataion;
	FVector TempGlobalTargetLocation;

	void AddActiveTrigger();
	void RemoveActiveTrigger();
};
