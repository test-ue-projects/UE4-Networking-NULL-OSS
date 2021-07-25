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

void UMainMenu::HostServer()
{
	UE_LOG(LogTemp, Warning, TEXT("HostServer pressed"));
}

void UMainMenu::JoinServer()
{
	UE_LOG(LogTemp, Warning, TEXT("JoinServer pressed"));
}
	