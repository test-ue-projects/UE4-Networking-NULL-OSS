// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class TESTGAME01_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()

	public:
	virtual void NativeConstruct() override;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UTextBlock* MainMenuTxt = nullptr;

	
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UButton* HostBtn = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UButton* JoinBtn= nullptr;
	
	
};
