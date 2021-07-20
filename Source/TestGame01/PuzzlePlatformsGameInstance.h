// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"


#include "PuzzlePlatformsGameInstance.generated.h"

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

	UFUNCTION(Exec)
	void Host(); // создасть консольную команду Host

	UFUNCTION(Exec)
	void Join(const FString& Address); // создасть консольную команду Host	          
};
