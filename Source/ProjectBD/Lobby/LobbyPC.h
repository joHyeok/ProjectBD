// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "LobbyPC.generated.h"

/**
 *
 */
UCLASS()
class PROJECTBD_API ALobbyPC : public APlayerController
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "UI")
		TSubclassOf<class ULobbyWidgetBase> LobbyWidgetClass;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "UI")
		class ULobbyWidgetBase* LobbyWidgetObject;

	virtual void BeginPlay() override;

	UFUNCTION(Server, Reliable)
	void C2S_AddText(const FText& Text);
	void C2S_AddText_Implementation(const FText& Text);

	UFUNCTION(Client, Reliable)
	void S2C_AddText(const FText& Text);
	void S2C_AddText_Implementation(const FText& Text);
};
