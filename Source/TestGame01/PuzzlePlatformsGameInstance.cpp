// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzzlePlatformsGameInstance.h"
#include "Kismet/GameplayStatics.h"

UPuzzlePlatformsGameInstance::UPuzzlePlatformsGameInstance()
{

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

	UGameplayStatics::GetPlayerController(GetWorld(), 0)->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
}
