// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor2.h"
#include "MyProject1.h"

// Sets default values
AMyActor2::AMyActor2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

// Called when the game starts or when spawned
void AMyActor2::BeginPlay()
{
	Super::BeginPlay();

	SetActorLocation(FVector::ZeroVector);

	FVector Location = GetActorLocation();
	UE_LOG(LogTemp, Warning, TEXT("시작 위치: (%.2f, %.2f)"), Location.X, Location.Y);
}

// Called every frame
void AMyActor2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MoveTimer += DeltaTime;
	if (MoveTimer >= 0.016666f)
	{
		Move();
		MoveTimer = 0;
	}
}


double AMyActor2::Step() const
{
	return FMath::RandBool()? 1.0 : 0.0;
}

void AMyActor2::Move()
{
	FVector PreviousLocation = GetActorLocation();
	AddActorWorldOffset(FVector(Step(), Step(), 0));
	FVector Location = GetActorLocation();
	double StepDistance = FVector::Dist2D(PreviousLocation, Location);
	TotalDistance += StepDistance;
	UE_LOG(LogMyProject, Warning, TEXT("Step 이동거리: %.f"), StepDistance);

	if (CreateEvent(50))
		++TotalEvents;

	++MoveCount;
	if (MoveCount >= 10)
	{
		UE_LOG(LogMyProject, Warning, TEXT("--------------------------------------------------------------"))
		UE_LOG(LogMyProject, Warning, TEXT("총 이동 거리: %f"), TotalDistance);
		UE_LOG(LogMyProject, Warning, TEXT("총 이벤트 발생 횟수: %d"), TotalEvents);

		TotalDistance = 0;
		TotalEvents = 0;
		MoveCount = 0;
		UE_LOG(LogMyProject, Warning, TEXT("================================================================"))
		UE_LOG(LogMyProject, Warning, TEXT("시작 위치: (%.2f, %.2f)"), Location.X, Location.Y);
	}
	else
	{
		UE_LOG(LogMyProject, Warning, TEXT("현재 위치: (%.2f, %.2f)"), Location.X, Location.Y);
	}
}

bool AMyActor2::CreateEvent(int32 Probability) const
{
	if (FMath::RandRange(1, 100) <= Probability)
	{
		UE_LOG(LogMyProject, Warning, TEXT("***이벤트 발생***"));
		return true;
	}
	UE_LOG(LogMyProject, Warning, TEXT("---이벤트 미발생---"));
	return false;
}
