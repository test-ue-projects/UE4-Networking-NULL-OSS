// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"
#include "Kismet/KismetMathLibrary.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	SetMobility(EComponentMobility::Movable);


	Speed = 10.f;
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if(HasAuthority())
	{
	
		FVector Location = GetActorLocation();
		//переводит локальные координаты в мировые
		FVector GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
		//
		FVector Direction = (GlobalTargetLocation - Location).GetSafeNormal();
		Location += Speed*DeltaTime*Direction;
		SetActorLocation(Location);

		///////////////////////////my var2////////////////////////////////
		// FVector StartLocation = GetActorLocation();	
		//
		// // Delta Move, Clamp so we do not over shoot. так как таргет локейшн в локльныйх координатах (тоесть Старт локайшн для таргет локейшена всегда буедт 0 0 0, мы можем не высчитывать вектор мировой который был бы разница между таргет и  старт локейшном)
		// const FVector	DeltaMove = TargetLocation * FMath::Clamp<float>(DeltaTime * Speed, 0.f, 1.f);
		//
		// SetActorLocation (StartLocation + DeltaMove);

		
	}
	
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	if(HasAuthority())
	{
		//просто параметры, могут быть и в конструкторе
		// не обязательно на бегин плей
		SetReplicates(true);
		SetReplicateMovement(true);

		
	}

}
