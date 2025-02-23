// Fill out your copyright notice in the Description page of Project Settings.


#include "CppHubActor.h"
#include "TimerManager.h"
#include "CppBaseActor1.h"

// Sets default values
ACppHubActor::ACppHubActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACppHubActor::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &ACppHubActor::OnTimeToSpawn, SpawnTimerRate, true);
}

// Called every frame
void ACppHubActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACppHubActor::OnTimeToSpawn()
{
	if (++CurrentTimerCount <= TotalCount)
	{
		const FVector Location = GetActorLocation() + FVector(FMath::FRandRange(200.f, 1000.f), FMath::FRandRange(200.0f, 1000.0f), 0.0f);
		const FRotator Rotation = FRotator::ZeroRotator;
		ACppBaseActor1* SpawnObject = GetWorld()->SpawnActor<ACppBaseActor1>(CppClass, Location, Rotation);
		if (SpawnObject)
		{
			SpawnedObjects.Add(SpawnObject);
		}
	}
	else
	{
		GetWorldTimerManager().ClearTimer(SpawnTimerHandle);
		for (int i = TotalCount; i >=1; --i)
		{
			GetWorldTimerManager().SetTimer(DestroyTimerHandle, this, &ACppHubActor::OnTimeToDestroy, DestroyTimerRate, true);
		}
	}
}

void ACppHubActor::OnTimeToDestroy()
{
	if (!SpawnedObjects.IsEmpty())
	{
		SpawnedObjects.Top()->Destroy();
		SpawnedObjects.Pop();
	}
	else
	{
		GetWorldTimerManager().ClearTimer(DestroyTimerHandle);
	}
}