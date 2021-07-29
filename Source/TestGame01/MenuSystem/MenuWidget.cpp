// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuWidget.h"

void UMenuWidget::SetMenuInterface(IMenuInterface* InMenuInterface)
{
	//this-> to remove ambiguity
	this->MenuInterface = InMenuInterface;   
}

void UMenuWidget::Setup()
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

void UMenuWidget::TierDown()
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
