// Fill out your copyright notice in the Description page of Project Settings.


#include "MoleGenerator.h"
#include "Kismet/KismetMathLibrary.h"
#include <functional>

AMoleGenerator::AMoleGenerator()
{
	PrimaryActorTick.bCanEverTick = true;
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;
}

void AMoleGenerator::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle GenerateTimer;

	GetWorldTimerManager().SetTimer(GenerateTimer, this, &AMoleGenerator::GenerateNumber, 3.f, true);
	
}

void AMoleGenerator::GenerateNumber()
{
	int32 RandomNumber = UKismetMathLibrary::RandomIntegerInRange(0, 8);
	
	while (PreviousHole == RandomNumber)
	{
		RandomNumber = UKismetMathLibrary::RandomIntegerInRange(0, 8);
	}
	PreviousHole = RandomNumber;
	SpawnMole(RandomNumber);
}

void AMoleGenerator::KillMole(AActor* Mole)
{
	if (Mole)
	{
		Mole->Destroy();
	}
}

void AMoleGenerator::SpawnMole(int32 Index)
{
	FVector SpawnLocation = Holes[Index]->GetActorLocation();
	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;

	AActor* Mole = GetWorld()->SpawnActor<AActor>(SpawnClass, SpawnLocation, FRotator::ZeroRotator, SpawnParams);

	FTimerHandle KillTimer;
	auto TimerCallback = std::bind(&AMoleGenerator::KillMole, this, Mole);
	GetWorldTimerManager().SetTimer(KillTimer, TimerCallback, 1.f, false);
}

void AMoleGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

