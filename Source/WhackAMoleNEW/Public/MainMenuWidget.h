// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuWidget.generated.h"

class UButton;

/**
 * 
 */
UCLASS()
class WHACKAMOLENEW_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UFUNCTION()
	void StartClicked();

	UFUNCTION()
	void ExitClicked();
	
protected:

	virtual void NativeConstruct() override;

private:

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> StartButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> ExitButton;

};
