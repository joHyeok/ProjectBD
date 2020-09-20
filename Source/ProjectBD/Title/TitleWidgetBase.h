// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TitleWidgetBase.generated.h"

/**
 *
 */
UCLASS()
class PROJECTBD_API UTitleWidgetBase : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "UI")
		class UButton* ConnectServerButton;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "UI")
		class UButton* StartServerButton;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "UI")
		class UEditableTextBox* ServerIP;

	virtual void NativeConstruct() override;

	UFUNCTION()
	void ConnectServer();

	UFUNCTION()
	void StartServer();
};
