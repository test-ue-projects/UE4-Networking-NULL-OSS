// Copyright Epic Games, Inc. All Rights Reserved.

#include "TestGame01GameMode.h"
#include "TestGame01Character.h"
#include "UObject/ConstructorHelpers.h"
#include "Net/UnrealNetwork.h"
#include "GameFramework/PlayerStart.h"

ATestGame01GameMode::ATestGame01GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void ATestGame01GameMode::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{

	DOREPLIFETIME(ATestGame01GameMode, CurrentPawnToAssign);
}

UClass* ATestGame01GameMode::GetDefaultPawnClassForController_Implementation(AController* InController)
{
	CurrentPawnToAssign = MainPlayerCharacter;    
	
	return CurrentPawnToAssign;
}

APlayerStart* ATestGame01GameMode::CustomPlayerStartLogic(AController* Player)
{
	FActorSpawnParameters SpawnInfo;
	SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;		
	
	auto PlayerStartActor =  GetWorld()->SpawnActor<APlayerStart>(
		APlayerStart::StaticClass(),
		PlayerSpawnLocation,
		FRotator::ZeroRotator,
		SpawnInfo);  

	  	
	return PlayerStartActor;
}

AActor* ATestGame01GameMode::ChoosePlayerStart_Implementation(AController* Player)
{
	return CustomPlayerStartLogic(Player);
}
