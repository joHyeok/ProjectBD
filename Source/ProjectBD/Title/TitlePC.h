// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TitlePC.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTBD_API ATitlePC : public APlayerController
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "UI")
		TSubclassOf<class UTitleWidgetBase> TitleWidgetClass;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "UI")
		class UTitleWidgetBase* TitleWidgetObject;

	virtual void BeginPlay() override;

	void StartServer();

	void ConnectServer(FString NewLevel);

};
