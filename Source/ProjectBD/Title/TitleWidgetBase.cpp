// Fill out your copyright notice in the Description page of Project Settings.


#include "TitleWidgetBase.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "TitlePC.h"

void UTitleWidgetBase::NativeConstruct()
{
	Super::NativeConstruct();

	ConnectServerButton = Cast<UButton>(GetWidgetFromName(TEXT("ConnectServerButton_BP")));
	StartServerButton = Cast<UButton>(GetWidgetFromName(TEXT("StartServerButton_BP")));
	ServerIP = Cast<UEditableTextBox>(GetWidgetFromName(TEXT("ServerIP_BP")));

	if (ConnectServerButton)
	{
		ConnectServerButton->OnClicked.AddDynamic(this, &UTitleWidgetBase::ConnectServer);
	}

	if (StartServerButton)
	{
		StartServerButton->OnClicked.AddDynamic(this, &UTitleWidgetBase::StartServer);
	}
}

void UTitleWidgetBase::ConnectServer()
{
	ATitlePC* PC = GetOwningPlayer<ATitlePC>();
	if (PC)
	{
		FString ServerIPAdress = ServerIP->GetText().ToString();
		PC->ConnectServer(ServerIPAdress);
	}
}

void UTitleWidgetBase::StartServer()
{
	ATitlePC* PC = GetOwningPlayer<ATitlePC>();
	if (PC)
	{
		PC->StartServer();
	}

}