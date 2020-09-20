// Fill out your copyright notice in the Description page of Project Settings.


#include "BattlePC.h"
#include "BattleWidgetBase.h"

void ABattlePC::BeginPlay()
{
	if (BattleWidgetClass)
	{
		BattleWidgetObject = CreateWidget<UBattleWidgetBase>(this, BattleWidgetClass);
		BattleWidgetObject->AddToViewport();
	}
}
