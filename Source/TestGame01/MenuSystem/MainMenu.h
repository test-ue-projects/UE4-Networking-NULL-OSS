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

protected:
	virtual void NativeConstruct() override;

	virtual bool Initialize() override;

public:
	
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UTextBlock* MainMenuTxt = nullptr;

	
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UButton* HostBtn = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UButton* JoinBtn= nullptr;
	
	UFUNCTION()
	void HostServer();

	UFUNCTION()
	void JoinServer();
};
