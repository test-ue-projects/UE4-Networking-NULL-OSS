// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TestGame01GameMode.generated.h"

UCLASS(minimalapi)
class ATestGame01GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ATestGame01GameMode();
	
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	//класс для спавна. Заменяет дефолтный, коотрый теперь Ноне
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player")
	TSubclassOf<class ATestGame01Character> MainPlayerCharacter;

	//локейшн для спавна
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player")
	FVector PlayerSpawnLocation;

	//нужен для репликации
	UPROPERTY(Replicated)
	TSubclassOf<ACharacter> CurrentPawnToAssign;

	// сохраненный блупринтовый класс  после поиска в конструкторе
	//todo: сделать ТАррей классов АОВЧарактер, и после нахождения в конструкторе  каждого  булпринтового класса,  его добавлять в этот массив. Потом В зависимости от парамтеров с сервера (хз что там) выбирать нужный класс и спавнить инстанс
	TSubclassOf<class ATestGame01Character> FElfBPClass;

	//оверрайдю для того чтобы сюда передавать свой павн класс, и он устанавливался как дефаулт
	virtual  UClass* GetDefaultPawnClassForController_Implementation(AController* InController) override;


	// создаю плеер старт актор, потом в ChoosePlayerStart_Implementation вызывается и где-то в глубинах движка этот спот устанавливается как спавн локейшн
	UFUNCTION(BlueprintPure, Category=Game, meta=(DisplayName="CustomPlayerStart"))
	class APlayerStart* CustomPlayerStartLogic(AController* Player);	
	
	// возвращает актора на месте коотрого заспавнится дефаулт павн. Эта ф-я срабатывает в комплексе других раньше чем BeginPlay и раньше GM вентов (последовательность срабатывания ивентов: ChoosePlayerStart - OnPostLogin(Ивент) - InitStartSpot (Ивент) - OnRestartPlayer (Ивент)) 
	virtual AActor* ChoosePlayerStart_Implementation(AController* Player) override;	
};



