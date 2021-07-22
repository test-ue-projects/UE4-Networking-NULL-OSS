// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"


#include "PuzzlePlatformsGameInstance.generated.h"


class UUserWidget;

/**
 * 
 */
UCLASS()
class TESTGAME01_API UPuzzlePlatformsGameInstance : public UGameInstance
{
	GENERATED_BODY()

	public:
	
	UPuzzlePlatformsGameInstance();

	virtual void Init() override;

	UUserWidget* Menu;		
	
	UFUNCTION(BlueprintCallable, Exec)
	UUserWidget* LoadMenu(); // создасть консольную команду Host

	UFUNCTION(Exec)
	void Host(); // создасть консольную команду Host

	UFUNCTION(Exec)
	void Join(const FString& Address); // создасть консольную команду Host

	/** The Menu widget class used by players. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Classes)
	TSubclassOf<UUserWidget> MenuClass;
};
