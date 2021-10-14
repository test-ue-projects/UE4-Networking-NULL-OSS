// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "MenuSystem/MenuInterface.h"
#include "Engine/GameInstance.h"
#include "OnlineSessionSettings.h"

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

	//интерфейсная ф-я,
	UFUNCTION(Exec)
	void Host() override; // создасть консольную команду Host, также так как мы насоедовались от интерфейса в котором есть функция с таким же именем то теперь это относится к интерфейсной ыункции

	//интерфейсная ф-я, подследенится к выбранной в списке сессии
	UFUNCTION()
	void Join(int32 Index) override; 

	//интерфейсная ф-я, c консольной командоай. Подсоеденится по прямому вводу IP  
	UFUNCTION(Exec)
	void JoinIP(const FString& IPAddr) override; // создасть консольную команду Host

	/** The  widget class used by players. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Classes)
	TSubclassOf<UUserWidget> MenuClass;

	/** The  widget class used by players. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Classes)
	TSubclassOf<UUserWidget> QuitMenuClass;

	//интерфейсная ф-я, quit to main menu
	UFUNCTION(Exec)	 
	void QuitGame() override;
	
	//close the game completly
	UFUNCTION(Exec)	
	void ExitGame() override;

	/////online subsystem///////
	class IOnlineSubsystem* OnlineSubsystemPtr;
	IOnlineSessionPtr SessionInterface;		

	//ф-я создает переход в уровень после создания сессии. Вызывается по средством коллбека от делегата OnCreateSessionCompleteDelegates после нажатия на Host 
	void OnCreateSessionComplete(FName SessionName, bool bSuccess);

	//ф-я вызывается после удаления сессии по средством каллбека от делегата OnDestroySessionCompleteDelegates  
	void OnDestroySessionComplete(FName SessionName, bool bSuccess);

	void OnFindSessionComplete(bool bSuccess);

	//указатель на структруру натсроек, создаем здесь так как она остается неизенной пока что. Также там будут храниться найденые сессии
	TSharedPtr<class FOnlineSessionSearch> SessionSearch;

	//создает сессию
	void CreateSession();

	//интерфейсная ф-я, рефрешит список серверов по запросу
	UFUNCTION(Exec)	
	void RefreshServerList() override;

	FOnlineSessionSearchResult SearchResult;

	void OnJoinSessionComplete(FName, EOnJoinSessionCompleteResult::Type);
};




