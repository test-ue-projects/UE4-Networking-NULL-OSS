// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuWidget.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class TESTGAME01_API UMainMenu : public UMenuWidget
{
	GENERATED_BODY()

public:
	// конструктор для нахождения блупринт виджета
	UMainMenu(); //const FObjectInitializer & ObjectInitializer

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
	
	// the name of variable and the name of the widget in the UMG must be the same, for bind to work correctly
	UPROPERTY(meta = (BindWidget))
	class UButton* ExitBtn=nullptr;

	// the name of variable and the name of the widget in the UMG must be the same, for bind to work correctly. кнопка относящаяяся к ServerList функционалу
	UPROPERTY(meta = (BindWidget))
	class UButton* JoinSessionBtn_1=nullptr;

	// the name of variable and the name of the widget in the UMG must be the same, for bind to work correctly. Кнопка относящаяяся к функционалу ввода прямого IP
	UPROPERTY(meta = (BindWidget))
	class UWidget* JoinSessionMenu= nullptr;
	
	// the name of variable and the name of the widget in the UMG must be the same, for bind to work correctly
	UPROPERTY(meta = (BindWidget))
	class UPanelWidget* ServerList = nullptr;

	// блупринтовый класс для сервер роу виджета.
	TSubclassOf<class UServerRow> ServerRowClass;

	//session index
	TOptional<int32> SelectedIndex;
	
protected:
	
	virtual void NativeConstruct() override;

	virtual bool Initialize() override;

public:
	UFUNCTION()
	void HostServer();

	//подсодинения по прямому IP
	UFUNCTION()
	void JoinServer();

	//switch to join menu
	UFUNCTION()	   
	void OpenJoinMenu();

	//switch to main menu
	UFUNCTION()
	void OpenMainMenu();

	//exit the game completely
	UFUNCTION()	 
	void CloseGame();

	//присоединение по выбору сервера из списка
	UFUNCTION()	 
	void JoinSession();

	//
	void SetServerList(TArray<FString>);

	//выбор индекса сессии-сервера
	void SelectIndex(int32 Index);

};
