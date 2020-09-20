// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BattleWidgetBase.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTBD_API UBattleWidgetBase : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		class UButton* ButtonOne;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		class UButton* ButtonTwo;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		class UButton* ButtonThree;

	virtual void NativeConstruct() override;

	UFUNCTION()
		void PressColorButton();

	UFUNCTION()
		void ReleaseColorButton();
};
