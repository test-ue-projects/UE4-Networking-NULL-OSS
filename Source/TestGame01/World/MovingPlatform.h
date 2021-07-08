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



	public:
	UPROPERTY(EditAnywhere, Category = "Params")
	float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Params", Meta = (MakeEditWidget = true))
	FVector TargetLocation;
	
};
