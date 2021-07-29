// Fill out your copyright notice in the Description page of Project Settings.


#include "ExitMenu.h"
#include "Components/Button.h"

bool UExitMenu::Initialize()
{
	bool Success = Super::Initialize();
	if(!Success) {return false;} //double check the pointers  		


	if(!ensure(CancelQuitBtn!=nullptr)) return false;  //double check the pointers
	CancelQuitBtn->OnPressed.AddDynamic(this, &UExitMenu::ReturnToGame);

	if(!ensure(QuitGameBtn!=nullptr)) return false;  //double check the pointers
	QuitGameBtn->OnPressed.AddDynamic(this, &UExitMenu::QuitGame);   

	return true;
}

void UExitMenu::ReturnToGame()
{
	UE_LOG(LogTemp, Warning, TEXT("ReturnToMainMenu pressed"));

	RemoveFromParent();

	TierDown();
}

void UExitMenu::QuitGame()
{
	UE_LOG(LogTemp, Warning, TEXT("QuitGame pressed"));

	if(MenuInterface != nullptr)
	{
		
		MenuInterface->QuitGame();
	}	  
}
