// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu.h"
#include "Components/TextBlock.h"
#include "Internationalization/Text.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Components/EditableText.h"

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
	
	if(!ensure(JoinMenuBtn!=nullptr)) return false;  //double check the pointers
	JoinMenuBtn->OnPressed.AddDynamic(this, &UMainMenu::OpenJoinMenu);

	if(!ensure(JoinBtn!=nullptr)) return false;  //double check the pointers
	JoinBtn->OnPressed.AddDynamic(this, &UMainMenu::JoinServer);

	if(!ensure(CancelJoinMenuBtn!=nullptr)) return false;  //double check the pointers
	CancelJoinMenuBtn->OnPressed.AddDynamic(this, &UMainMenu::OpenMainMenu);

	if(!ensure(ExitBtn!=nullptr)) return false;  //double check the pointers
	ExitBtn->OnPressed.AddDynamic(this, &UMainMenu::CloseGame);
	
	return true;
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
	FString IpAddr = IpAddrArea->GetText().ToString();	 
	
	if(MenuInterface != nullptr && IpAddr != "")
	{
		
		MenuInterface->Join(IpAddr);
	}
}

void UMainMenu::OpenJoinMenu()
{
	MenuSwitch->SetActiveWidget(JoinMenu);	
}

void UMainMenu::OpenMainMenu()
{
	MenuSwitch->SetActiveWidget(MainMenuArea);
}

void UMainMenu::CloseGame()
{
	if(MenuInterface != nullptr)
	{
		
		MenuInterface->ExitGame();
	}  
}
