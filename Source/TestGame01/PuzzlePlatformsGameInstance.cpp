// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzzlePlatformsGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"
#include "World/PlatformTrigger.h"
#include "GameFramework/PlayerController.h"
#include "Blueprint/UserWidget.h"
#include "MenuSystem/MainMenu.h"

UPuzzlePlatformsGameInstance::UPuzzlePlatformsGameInstance()
{
	// using BP in c++ - set menu class class to our Blueprinted character. There is na example in Default Game Mode cal
	ConstructorHelpers::FClassFinder<UMainMenu> MenuBPClass(TEXT("/Game/MenuSystem/WB_MainMenu"));
	if (MenuBPClass.Class != NULL)
	{
		MenuClass = MenuBPClass.Class;
	}		 
}

void UPuzzlePlatformsGameInstance::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("On init %s"), *MenuClass->GetName());		  
}

void UPuzzlePlatformsGameInstance::LoadMenu()
{
	//double check that the BP exists
	if(!ensure(MenuClass!=nullptr)){return;}

	
	Menu = CreateWidget<UMainMenu>(this, MenuClass);

	if(!ensure(Menu!=nullptr)){return;}
	Menu->AddToViewport();

	Menu->Setup();

	//сохраняет в меню указатель на этот конкрентынй гейм инстанс, потому что ГМ знает о существовании Меню, а мены не занет о существовании ПазлПлатформГМ но знает про совой интерфейс
	Menu->SetMenuInterface(this);

}

void UPuzzlePlatformsGameInstance::Host()
{
	UWorld* World = GetWorld();
	
	if(!ensure(World!=nullptr)){return;}

	//так как это консольная команда и может быть вызвана из командной стороки то Menu не обязательно должен присутствоватб
	if(Menu != nullptr)
	{
		Menu->TierDown();
	}

	//on call of thos function - specify the server as a listener server, makes the client which is calling this function as a server 
	World->ServerTravel("/Game/Static/Maps/ThirdPersonExampleMap?listen");
}

void UPuzzlePlatformsGameInstance::Join(const FString& Address)
{
	/*if(GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(TEXT("Join to %s address"), *Address));
	}*/

	//так как это консольная команда и может быть вызвана из командной стороки то Menu не обязательно должен присутствоватб
	if(Menu != nullptr)
	{
		Menu->TierDown();
	}

	APlayerController* PlayerController = GetFirstLocalPlayerController(GetWorld());
	if(!ensure(PlayerController!=nullptr)){return;}

	PlayerController->ClientTravel(Address, ETravelType::TRAVEL_Absolute);

	UGameplayStatics::GetPlayerController(GetWorld(), 0)->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
}
