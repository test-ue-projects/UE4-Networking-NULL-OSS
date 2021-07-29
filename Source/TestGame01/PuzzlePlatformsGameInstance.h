// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuSystem/MenuInterface.h"
#include "Engine/GameInstance.h"


#include "PuzzlePlatformsGameInstance.generated.h"


class UUserWidget;

/**
 * 
 */
UCLASS()
class TESTGAME01_API UPuzzlePlatformsGameInstance : public UGameInstance, public IMenuInterface
{
	GENERATED_BODY()

	public:
	
	UPuzzlePlatformsGameInstance();

	virtual void Init() override;

	class UMainMenu* Menu;
	class UExitMenu* QuitMenu;
	
	UFUNCTION(BlueprintCallable, Exec)
	void LoadMenu(); // создасть консольную команду Host

	UFUNCTION(BlueprintCallable, Exec)
	void QuitMenuCall(); // создасть консольную команду Host

	UFUNCTION(Exec)
	void Host() override; // создасть консольную команду Host, также так как мы насоедовались от интерфейса в котором есть функция с таким же именем то теперь это относится к интерфейсной ыункции

	UFUNCTION(Exec)
	void Join(const FString& Address) override; // создасть консольную команду Host

	/** The  widget class used by players. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Classes)
	TSubclassOf<UUserWidget> MenuClass;

	/** The  widget class used by players. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Classes)
	TSubclassOf<UUserWidget> QuitMenuClass;

	//quit to main menu
	UFUNCTION(Exec)	 
	void QuitGame() override;


	//close the game completly
	UFUNCTION(Exec)	
	void ExitGame() override;
};
