// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGM.h"

void ALobbyGM::GameStart()
{
	GetWorld()->ServerTravel(TEXT("Battle"));
}
