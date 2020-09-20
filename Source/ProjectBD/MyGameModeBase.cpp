// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "BasicPlayer.h"
#include "Kismet/GameplayStatics.h"

AMyGameModeBase::AMyGameModeBase()
{
	//ABasicPlayer* Player = Cast<ABasicPlayer>(Get);
	TArray<AActor*> Output;
	UGameplayStatics::GetAllActorsOfClassWithTag(GetWorld(), ABasicPlayer::StaticClass(), TEXT("Target"), Output);
	UE_LOG(LogClass, Warning, TEXT("GameMode Output Num : %d"), Output.Num());
}

void AMyGameModeBase::CheckGameRule()
{
	//TArray<AActor*> Output;
	//UGameplayStatics::GetAllActorsOfClassWithTag(GetWorld(), ABasicPlayer::StaticClass(), TEXT("Target"), Output);
	//UE_LOG(LogClass, Warning, TEXT("GameMode Output Num : %d"), Output.Num());
	//if (Output.Num() == 0)
	//{
	//	UE_LOG(LogClass, Warning, TEXT("OpenLevel 02"));
	//
	//	UGameplayStatics::OpenLevel(GetWorld(), TEXT("Map02"));
	//}
}
