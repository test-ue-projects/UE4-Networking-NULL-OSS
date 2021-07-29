// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuInterface.h"
#include "MenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class TESTGAME01_API UMenuWidget : public UUserWidget
{
	GENERATED_BODY()

	public:
	void SetMenuInterface(IMenuInterface* InMenuInterface);

	//set show Cursor and UIOnly mode
	void Setup();

	//set hide Cursor and GameOnly mode	 
	void TierDown();

	protected:
	
	IMenuInterface* MenuInterface;
	
};
