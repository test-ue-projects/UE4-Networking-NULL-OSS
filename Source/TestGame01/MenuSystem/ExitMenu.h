// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuWidget.h"
#include "ExitMenu.generated.h"

/**
 * 
 */
UCLASS()
class TESTGAME01_API UExitMenu : public UMenuWidget
{
	GENERATED_BODY()


	private:
	
	// the name of variable and the name of the widget in the UMG must be the same, for bind to work correctly
	UPROPERTY(meta = (BindWidget))
	class UButton* CancelQuitBtn= nullptr;

	// the name of variable and the name of the widget in the UMG must be the same, for bind to work correctly
	UPROPERTY(meta = (BindWidget))
	class UButton*  QuitGameBtn= nullptr;

	public:

	virtual bool Initialize() override;

	UFUNCTION()	
	void ReturnToGame();

	UFUNCTION()		  
	void QuitGame();

};
