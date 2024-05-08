// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GameHUD.generated.h"

class UMainMenuWidget;

/**
 * 
 */
UCLASS()
class WHACKAMOLENEW_API AGameHUD : public AHUD
{
	GENERATED_BODY()

protected:

	virtual void BeginPlay() override;

private:

	UPROPERTY(EditAnywhere, Category = Class)
	TSubclassOf<UMainMenuWidget> MainMenuClass;

	UPROPERTY()
	TObjectPtr<UMainMenuWidget> MainMenu;
	
};
