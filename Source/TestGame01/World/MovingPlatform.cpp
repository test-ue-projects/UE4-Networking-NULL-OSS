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
	
	if(ActiveTriggers > 0)
	{
		if(HasAuthority())
		{	
			FVector Location = GetActorLocation();
			float JourneyLength = (GlobalTargetLocation - GlobalStartLocataion).Size();
			float JourneyTraveled = (Location - GlobalStartLocataion).Size();

			if(JourneyTraveled >= JourneyLength)
			{
				FVector Swap = GlobalStartLocataion;
				GlobalStartLocataion = GlobalTargetLocation;
				GlobalTargetLocation = Swap;
			}
		
			FVector Direction = (GlobalTargetLocation - GlobalStartLocataion).GetSafeNormal();				
			Location += Speed*DeltaTime*Direction;			
			SetActorLocation(Location);
		}
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

	GlobalStartLocataion = GetActorLocation();
	//переводит локальные координаты в мировые
	 GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);

	TempGlobalStartLocataion = GlobalStartLocataion ;
	TempGlobalTargetLocation = GlobalTargetLocation;
}

void AMovingPlatform::AddActiveTrigger()
{
	ActiveTriggers++;
}

void AMovingPlatform::RemoveActiveTrigger()
{
	if(ActiveTriggers >0)
	{
		ActiveTriggers--;
	}
}
