// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyWidgetBase.h"
#include "Components/TextBlock.h"
#include "Components/ScrollBox.h"
#include "Components/EditableTextBox.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "LobbyPC.h"
#include "LobbyGM.h"

void ULobbyWidgetBase::NativeConstruct()
{
	Super::NativeConstruct();

	LeftTime = Cast<UTextBlock>(GetWidgetFromName(TEXT("LeftTime_BP")));
	CountPlayer = Cast<UTextBlock>(GetWidgetFromName(TEXT("CountPlayer_BP")));
	ChatBox = Cast<UScrollBox>(GetWidgetFromName(TEXT("ChatBox_BP")));
	InputChatBox = Cast<UEditableTextBox>(GetWidgetFromName(TEXT("InputChatBox_BP")));
	GameStartButton = Cast<UButton>(GetWidgetFromName(TEXT("GameStartButton_BP")));

	if (InputChatBox)
	{
		InputChatBox->OnTextCommitted.AddDynamic(this, &ULobbyWidgetBase::ProcessTextCommited);
	}

	if (GameStartButton)
	{
		GameStartButton->OnClicked.AddDynamic(this, &ULobbyWidgetBase::PushStartGameButton);
	}
}

void ULobbyWidgetBase::ProcessTextCommited(const FText& Text, ETextCommit::Type CommitMethod)
{
	switch (CommitMethod)
	{
	case ETextCommit::Default:
		break;
	case ETextCommit::OnEnter:
	{
		ALobbyPC* PC = GetOwningPlayer<ALobbyPC>();
		if (PC)
		{
			PC->C2S_AddText(Text);
			InputChatBox->SetText(FText::FromString(TEXT("")));
		}
	}
		break;
	case ETextCommit::OnUserMovedFocus:
		break;
	case ETextCommit::OnCleared:
		InputChatBox->SetUserFocus(GetOwningPlayer());
		break;
	default:
		break;
	}

}

void ULobbyWidgetBase::PushStartGameButton()
{
	ALobbyGM* GM = Cast<ALobbyGM>(UGameplayStatics::GetGameMode(GetWorld()));
	if (GM)
	{
		GM->GameStart();
	}
}

void ULobbyWidgetBase::AddMessage(const FText& Text)
{
	if (ChatBox)
	{
		UTextBlock* NewTextBlock = NewObject<UTextBlock>(ChatBox);
		if (NewTextBlock)
		{
			ChatBox->AddChild(NewTextBlock);
			NewTextBlock->SetText(Text);
			NewTextBlock->Font.Size = 18;
			ChatBox->ScrollToEnd();
		}
	}
}
