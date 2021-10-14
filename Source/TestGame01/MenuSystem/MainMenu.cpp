// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu.h"
#include "Components/TextBlock.h"
#include "Internationalization/Text.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Components/EditableText.h"
#include "Components/ScrollBox.h"
#include "ServerRow.h"
#include "Chaos/ChaosDebugDraw.h"


UMainMenu::UMainMenu()
{
	// using BP in c++. There is na example in Default Game Mode cal. КонструкторХелпер и FClassFinder всегда вызвается в конструкторе иначе он не будет работать, по этому если не создается явно конструктор как в случае этого класса, его нужно создать вручную.
	ConstructorHelpers::FClassFinder<UServerRow> ServerRowBPClass(TEXT("/Game/MenuSystem/WB_ServerRow"));
	if (ServerRowBPClass.Class != NULL)
	{
		ServerRowClass = ServerRowBPClass.Class;
	}      
}

void UMainMenu::NativeConstruct()
{
	Super::NativeConstruct();
	if(MainMenuTxt != nullptr)
	{
		MainMenuTxt->SetText(FText::FromString("Mein Menu"));
		
	}
}

bool UMainMenu::Initialize()
{
	bool Success = Super::Initialize();
	if(!Success) {return false;} //double check the pointers       

	if(!ensure(HostBtn!=nullptr)) return false;  //double check the pointers
	HostBtn->OnPressed.AddDynamic(this, &UMainMenu::HostServer);
	
	if(!ensure(JoinMenuBtn!=nullptr)) return false;  //double check the pointers
	JoinMenuBtn->OnPressed.AddDynamic(this, &UMainMenu::OpenJoinMenu);

	if(!ensure(JoinBtn!=nullptr)) return false;  //double check the pointers
	JoinBtn->OnPressed.AddDynamic(this, &UMainMenu::JoinServer);

	if(!ensure(CancelJoinMenuBtn!=nullptr)) return false;  //double check the pointers
	CancelJoinMenuBtn->OnPressed.AddDynamic(this, &UMainMenu::OpenMainMenu);

	if(!ensure(ExitBtn!=nullptr)) return false;  //double check the pointers
	ExitBtn->OnPressed.AddDynamic(this, &UMainMenu::CloseGame);

	if(!ensure(JoinSessionBtn_1!=nullptr)) return false;  //double check the pointers
	JoinSessionBtn_1->OnPressed.AddDynamic(this, &UMainMenu::JoinSession);
	
	return true;
}

void UMainMenu::HostServer()
{
	UE_LOG(LogTemp, Warning, TEXT("HostServer pressed"));
	
	if(MenuInterface != nullptr)
	{
		MenuInterface->Host();
	}
}

void UMainMenu::JoinServer()
{
	FString IpAddr = IpAddrArea->GetText().ToString();	 
	
	if(MenuInterface != nullptr && IpAddr != "")
	{
		
		MenuInterface->JoinIP(IpAddr);
	}
}

void UMainMenu::OpenJoinMenu()
{
	MenuSwitch->SetActiveWidget(JoinSessionMenu);

	//запустим поиск хостов и обновим список серверов при открытии джоин меню
	MenuInterface->RefreshServerList();
}

void UMainMenu::OpenMainMenu()
{
	MenuSwitch->SetActiveWidget(MainMenuArea);
}

void UMainMenu::CloseGame()
{
	if(MenuInterface != nullptr)
	{
		
		MenuInterface->ExitGame();
	}  
}

void UMainMenu::JoinSession()
{
	 if(SelectedIndex.IsSet() && MenuInterface != nullptr)
	 {
	 	UE_LOG(LogTemp, Warning, TEXT("Selected session index %d"), SelectedIndex.GetValue());
	 	MenuInterface->Join(SelectedIndex.GetValue());	 		
	 }
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Selected index is not set"));      
	}

}

void UMainMenu::SetServerList(TArray<FString> ServerNames)
{
	auto  World = this->GetWorld();
	if(!ensure(World !=nullptr)){return;}

	ServerList->ClearChildren();

	int32 Index = 0; //init index of server row      
	for(auto& ServerName : ServerNames)
	{
		auto RowWidget = CreateWidget<UServerRow>(World, ServerRowClass);
		if(!ensure(RowWidget !=nullptr)){return;}

		RowWidget->ServerName->SetText(FText::FromString(ServerName));
		RowWidget->Setup(this, Index);
		++Index;

		ServerList->AddChild(RowWidget); 
	}
	
}

void UMainMenu::SelectIndex(int32 Index)
{
	    SelectedIndex = Index;
}
