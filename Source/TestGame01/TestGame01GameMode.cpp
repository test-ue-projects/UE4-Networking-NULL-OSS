// Copyright Epic Games, Inc. All Rights Reserved.

#include "TestGame01GameMode.h"
#include "TestGame01Character.h"
#include "UObject/ConstructorHelpers.h"

ATestGame01GameMode::ATestGame01GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
