// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu.h"
#include "Components/TextBlock.h"
#include "Internationalization/Text.h"
#include "Components/Button.h"

void UMainMenu::NativeConstruct()
{

	Super::NativeConstruct();

	if(MainMenuTxt != nullptr)
	{
		MainMenuTxt->SetText(FText::FromString("Mein Menu"));
	}
}

bool UMainMenu::Initialize()
{
	bool Success = Super::Initialize();
	if(!Success) {return false;} //double check the pointers       

	if(!ensure(HostBtn!=nullptr)) return false;  //double check the pointers
	HostBtn->OnPressed.AddDynamic(this, &UMainMenu::HostServer);
	
	if(!ensure(JoinBtn!=nullptr)) return false;  //double check the pointers
	JoinBtn->OnPressed.AddDynamic(this, &UMainMenu::JoinServer);
	
	return true;
}

void UMainMenu::SetMenuInterface(IMenuInterface* InMenuInterface)
{
	//this-> to remove ambiguity
	this->MenuInterface = InMenuInterface;    
}

void UMainMenu::HostServer()
{
	UE_LOG(LogTemp, Warning, TEXT("HostServer pressed"));
	
	if(MenuInterface != nullptr)
	{
		MenuInterface->Host();
	}
}

void UMainMenu::JoinServer()
{
	UE_LOG(LogTemp, Warning, TEXT("JoinServer pressed"));
}

void UMainMenu::Setup()
{
	UWorld* World = GetWorld();
	if(!ensure(World!=nullptr)){return;}
	
	//setting preparations to set input mode and mouse coursor
    	FInputModeUIOnly InputModeData;
    	InputModeData.SetWidgetToFocus(this->TakeWidget());
    	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
    
    	APlayerController* PlayerController = World->GetFirstPlayerController();
    	if(!ensure(PlayerController!=nullptr)){return;}
    
    	PlayerController->SetInputMode(InputModeData);
    	PlayerController->bShowMouseCursor = true;

}

void UMainMenu::TierDown()
{
	UWorld* World = GetWorld();
	if(!ensure(World!=nullptr)){return;}
	
	///setting preparations to set input mode and mouse coursor
	FInputModeGameOnly InputModeData;	
	APlayerController* PlayerController = World->GetFirstPlayerController();
	if(!ensure(PlayerController!=nullptr)){return;}
	PlayerController->SetInputMode(InputModeData);
	PlayerController->bShowMouseCursor = false;
}
	