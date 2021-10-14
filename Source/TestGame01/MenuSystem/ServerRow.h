// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ServerRow.generated.h"

/**
 * 
 */
UCLASS()
class TESTGAME01_API UServerRow : public UUserWidget
{
	GENERATED_BODY()


	public:
	// the name of variable and the name of the widget in the UMG must be the same, for bind to work correctly
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* ServerName = nullptr;

	 //settingup the current serverrow with data
	void Setup(class UMainMenu* InParent, uint32 InIndex);

	//session-server button
	UPROPERTY(meta = (BindWidget))
	class UButton* RowBtn = nullptr;

private:
	//pass SelectIndex of selected server row to MainMenu
	UFUNCTION()
	void OnClickedBtn();	  

	//perent holder for this widget, when it is created
	class UMainMenu* Parent;

	//this widget index
	int32 Index;


	                 
};


