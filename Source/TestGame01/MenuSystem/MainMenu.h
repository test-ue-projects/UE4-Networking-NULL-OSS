// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuInterface.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class TESTGAME01_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()

private:

	// the name of variable and the name of the widget in the UMG must be the same, for bind to work correctly
	UPROPERTY( meta = (BindWidget))
	class UTextBlock* MainMenuTxt = nullptr;

	// the name of variable and the name of the widget in the UMG must be the same, for bind to work correctly
	UPROPERTY(meta = (BindWidget))
	class UButton* HostBtn = nullptr;

	// the name of variable and the name of the widget in the UMG must be the same, for bind to work correctly
	UPROPERTY(meta = (BindWidget))
	class UButton* JoinMenuBtn= nullptr;

	// the name of variable and the name of the widget in the UMG must be the same, for bind to work correctly
	UPROPERTY(meta = (BindWidget))
	class UButton* JoinBtn= nullptr;

	// the name of variable and the name of the widget in the UMG must be the same, for bind to work correctly
	UPROPERTY(meta = (BindWidget))
	class UButton* CancelJoinMenuBtn= nullptr;

	// the name of variable and the name of the widget in the UMG must be the same, for bind to work correctly
	UPROPERTY(meta = (BindWidget))
	class UWidgetSwitcher* MenuSwitch= nullptr;

	// the name of variable and the name of the widget in the UMG must be the same, for bind to work correctly
	UPROPERTY(meta = (BindWidget))
	class UWidget* JoinMenu= nullptr;

	// the name of variable and the name of the widget in the UMG must be the same, for bind to work correctly
	UPROPERTY(meta = (BindWidget))
	class UWidget* MainMenuArea= nullptr;

	
	// the name of variable and the name of the widget in the UMG must be the same, for bind to work correctly
	UPROPERTY(meta = (BindWidget))
	class UEditableText* IpAddrArea= nullptr; 

	
	IMenuInterface* MenuInterface;

protected:
	
	virtual void NativeConstruct() override;

	virtual bool Initialize() override;

public:

	//connect this widget with other object that implements this interface
	void SetMenuInterface(IMenuInterface* InMenuInterface);
	
	UFUNCTION()
	void HostServer();

	UFUNCTION()
	void JoinServer();

	//switch to join menu
	UFUNCTION()	   
	void OpenJoinMenu();

	//switch to main menu
	UFUNCTION()
	void OpenMainMenu();


	//set show Cursor and UIOnly mode
	void Setup();

	//set hide Cursor and GameOnly mode	 
	void TierDown();


};
