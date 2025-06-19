// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor1.h"
#include "MyProject1.h"

// Sets default values
AMyActor1::AMyActor1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AMyActor1::BeginPlay()
{
	Super::BeginPlay();

	Move();
}

double AMyActor1::Step() const
{
	return FMath::RandBool()? 1.0 : 0.0;
}

void AMyActor1::Move() const
{
	FVector Location = FVector::ZeroVector;
	UE_LOG(LogMyProject, Warning, TEXT("Start Location: (%.2f, %.2f)"), Location.X, Location.Y);

	for (int32 i = 0; i < 10; ++i)
	{
		Location += FVector(Step(), Step(),0.0);
		UE_LOG(LogMyProject, Warning, TEXT("Location %d: (%.2f, %.2f)"), i+1, Location.X, Location.Y);
	}
}

