// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor2.generated.h"

UCLASS()
class MYPROJECT1_API AMyActor2 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor2();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	double Step() const;
	void Move();
	bool CreateEvent(int32 Probability) const;

private:
	int32 TotalEvents = 0;
	int32 MoveCount = 0;
	double TotalDistance = 0.0;
	float MoveTimer = 0.0f;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
