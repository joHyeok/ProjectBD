// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LobbyWidgetBase.generated.h"

/**
 *
 */
UCLASS()
class PROJECTBD_API ULobbyWidgetBase : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "UI")
		class UTextBlock* LeftTime;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "UI")
		class UTextBlock* CountPlayer;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "UI")
		class UScrollBox* ChatBox;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "UI")
		class UEditableTextBox* InputChatBox;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "UI")
		class UButton* GameStartButton;

	virtual void NativeConstruct() override;

	UFUNCTION()
		void ProcessTextCommited(const FText& Text, ETextCommit::Type CommitMethod);

	UFUNCTION()
		void PushStartGameButton();

	void AddMessage(const FText& Text);
};
