// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleWidgetBase.h"
#include "Components/Button.h"

void UBattleWidgetBase::NativeConstruct()
{
	ButtonOne = Cast<UButton>(GetWidgetFromName(TEXT("ButtonNumber_1")));
	ButtonTwo = Cast<UButton>(GetWidgetFromName(TEXT("ButtonNumber_2")));
	ButtonThree = Cast<UButton>(GetWidgetFromName(TEXT("ButtonNumber_3")));

	ButtonOne->OnPressed.AddDynamic(this, &UBattleWidgetBase::PressColorButton);
	ButtonTwo->OnPressed.AddDynamic(this, &UBattleWidgetBase::PressColorButton);
	ButtonThree->OnPressed.AddDynamic(this, &UBattleWidgetBase::PressColorButton);

	ButtonOne->OnReleased.AddDynamic(this, &UBattleWidgetBase::ReleaseColorButton);
	ButtonTwo->OnReleased.AddDynamic(this, &UBattleWidgetBase::ReleaseColorButton);
	ButtonThree->OnReleased.AddDynamic(this, &UBattleWidgetBase::ReleaseColorButton);
}

void UBattleWidgetBase::PressColorButton()
{
	UE_LOG(LogClass, Warning, TEXT("PressColorButton"));
}

void UBattleWidgetBase::ReleaseColorButton()
{
	UE_LOG(LogClass, Warning, TEXT("ReleaseColorButton"));
}
