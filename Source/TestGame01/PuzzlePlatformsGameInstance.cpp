// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzzlePlatformsGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"
#include "World/PlatformTrigger.h"

UPuzzlePlatformsGameInstance::UPuzzlePlatformsGameInstance()
{
	// set default pawn class to our Blueprinted character
	ConstructorHelpers::FClassFinder<APlatformTrigger> PlatformTrigger(TEXT("/Game/Blueprints/MyPlatformTrigger"));
	if (PlatformTrigger.Class != NULL)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *PlatformTrigger.Class->GetName());
	}		 
}

void UPuzzlePlatformsGameInstance::Init()
{

}

void UPuzzlePlatformsGameInstance::Host()
{
	UWorld* World = GetWorld();
	if(!ensure(World!=nullptr)){return;}

	//on call of thos function - specify the server as a listener server, makes the client which is calling this function as a server 
	World->ServerTravel("/Game/Static/Maps/ThirdPersonExampleMap?listen");


}

void UPuzzlePlatformsGameInstance::Join(const FString& Address)
{
	if(GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(TEXT("Join to %s address"), *Address));
	}

	APlayerController* PlayerController = GetFirstLocalPlayerController(GetWorld());
	if(!ensure(PlayerController!=nullptr)){return;}

	PlayerController->ClientTravel(Address, ETravelType::TRAVEL_Absolute);

	//UGameplayStatics::GetPlayerController(GetWorld(), 0)->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
}
