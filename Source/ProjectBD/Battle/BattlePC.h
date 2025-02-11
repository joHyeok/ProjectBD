// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BattlePC.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTBD_API ABattlePC : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay()override;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "UI")
		TSubclassOf<class UBattleWidgetBase> BattleWidgetClass;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "UI")
		class UBattleWidgetBase* BattleWidgetObject;
	
};
