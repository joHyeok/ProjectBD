// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyPC.h"
#include "LobbyWidgetBase.h"

void ALobbyPC::BeginPlay()
{
	if (LobbyWidgetClass)
	{
		if (IsLocalPlayerController())
		{
			LobbyWidgetObject = CreateWidget<ULobbyWidgetBase>(this, LobbyWidgetClass);
			if (LobbyWidgetObject)
			{
				LobbyWidgetObject->AddToViewport();

				SetInputMode(FInputModeGameAndUI());
				bShowMouseCursor = true;
			}
		}
	}

}

void ALobbyPC::C2S_AddText_Implementation(const FText& Text)
{
	for (auto Iter = GetWorld()->GetPlayerControllerIterator(); Iter; Iter++)
	{
		ALobbyPC* PC = Cast<ALobbyPC>(*Iter);
		if (PC)
		{
			PC->S2C_AddText(Text);
		}
	}
}

void ALobbyPC::S2C_AddText_Implementation(const FText& Text)
{
	if (LobbyWidgetObject)
	{
		LobbyWidgetObject->AddMessage(Text);
	}
}
