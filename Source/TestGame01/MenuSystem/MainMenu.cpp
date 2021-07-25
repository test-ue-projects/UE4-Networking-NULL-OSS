// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu.h"
#include "Components/TextBlock.h"
#include "Internationalization/Text.h"

void UMainMenu::NativeConstruct()
{

	Super::NativeConstruct();

	if(MainMenuTxt != nullptr)
	{
		MainMenuTxt->SetText(FText::FromString("Mein Menu"));
	}
}
	