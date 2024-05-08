// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuWidget.h"
#include "Components/Button.h"

void UMainMenuWidget::NativeConstruct()
{
	Super:: NativeConstruct();

	if (StartButton)
	{
		StartButton->OnClicked.AddDynamic(this, &UMainMenuWidget::StartClicked);
	}
	if (ExitButton)
	{
		ExitButton->OnClicked.AddDynamic(this, &UMainMenuWidget::ExitClicked);
	}
}

void UMainMenuWidget::StartClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("STARTED"));
}

void UMainMenuWidget::ExitClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("EXITED"));
}

