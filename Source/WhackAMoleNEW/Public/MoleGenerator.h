// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MoleGenerator.generated.h"

UCLASS()
class WHACKAMOLENEW_API AMoleGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	AMoleGenerator();

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = Spawn)
		TSubclassOf<AActor> SpawnClass;

protected:
	virtual void BeginPlay() override;	

private:

	UPROPERTY(VisibleAnywhere)
		TObjectPtr<UStaticMeshComponent> MeshComp;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
		TArray<TObjectPtr<AActor>> Holes;

	UFUNCTION()
		void GenerateNumber();

	UFUNCTION()
		void KillMole(AActor* Mole);

	UFUNCTION()
		void SpawnMole(int32 Index);

	int32 PreviousHole;
};
