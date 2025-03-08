// Fill out your copyright notice in the Description page of Project Settings.

#include "CppBaseActor1.h"


// Sets default values
ACppBaseActor1::ACppBaseActor1()
{
	// Set this actor to call Tick() every frame.  You can turn this off to
	// improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
}

// Called when the game starts or when spawned
void ACppBaseActor1::BeginPlay()
{
	InitialLocation = GetActorLocation();
	Super::BeginPlay();
}

// Called every frame
void ACppBaseActor1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACppBaseActor1::ShowInformation()
{
	// UE_LOG(LogTemp, Display, TEXT("CppBase is here"));
	// UE_LOG(LogTemp, Warning, TEXT("CppBase Класс ошибся"));
	// UE_LOG(LogTemp, Error, TEXT("CppBase ошибка"));

	FString InstanceName = GetActorNameOrLabel();
	UE_LOG(LogTemp, Display, TEXT("Instance name : %s"), *InstanceName);
	UE_LOG(LogTemp, Display, TEXT("EnemyNum: %d"), EnemyNum);
	UE_LOG(LogTemp, Display, TEXT("IsAlive: %s"), IsAlive ? TEXT("1") : TEXT("0"));
}

void ACppBaseActor1::SinMovement()
{
	float TimeEvent = UGameplayStatics::GetTimeSeconds(GetWorld());
	FVector CurrentLocation = GetActorLocation();
	CurrentLocation += FVector(0.0f, 0.0f, (Amplitude * FMath::Sin(Frequency * TimeEvent)));
	SetActorLocation(CurrentLocation);
}
