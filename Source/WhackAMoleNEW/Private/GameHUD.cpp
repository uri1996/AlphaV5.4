// Fill out your copyright notice in the Description page of Project Settings.

#include "GameHUD.h"
#include "MainMenuWidget.h"

void AGameHUD::BeginPlay()
{
	Super::BeginPlay();

	UWorld* World = GetWorld();

	if (World && MainMenuClass)
	{
		MainMenu = CreateWidget<UMainMenuWidget>(World, MainMenuClass);
		MainMenu->AddToViewport();
	}

	if (APlayerController* PlayerController = World->GetFirstPlayerController())
	{
		PlayerController->bShowMouseCursor = true;
	}
}
