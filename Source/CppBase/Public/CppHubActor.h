// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CppHubActor.generated.h"

class ACppBaseActor1;
UCLASS()
class CPPBASE_API ACppHubActor : public AActor
{
	GENERATED_BODY()
public:
	// Sets default values for this actor's properties
	ACppHubActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	float SpawnTimerRate = 2.0f;

	UPROPERTY(EditAnywhere)
	float DestroyTimerRate = 1.0f;

	UPROPERTY()
	TArray<ACppBaseActor1*> SpawnedObjects;

	FTimerHandle SpawnTimerHandle;
	FTimerHandle DestroyTimerHandle;

	const int32 TotalCount = 10;
	int32		CurrentTimerCount = 0;

	void OnTimeToSpawn();
	void OnTimeToDestroy();

	UPROPERTY(EditAnywhere)
	TSubclassOf<ACppBaseActor1> CppClass;
};
