// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Item.h"
#include "DrawDebugHelpers.h"

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshComponent"));
	RootComponent = ItemMesh;
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	//SetActorLocation(FVector(0.f, 50.f, 50.f));
	//SetActorRotation(FRotator(0.f, 45.f, 0.f));
	UE_LOG(LogTemp, Warning, TEXT("Begin Play called!"));

	//UWorld* World = GetWorld();
	//if (nullptr != World)
	//{
	//	FVector Location = GetActorLocation();
	//	FVector Direction = GetActorForwardVector();
	//	DrawDebugSphere(World, Location, 25.f, 24, FColor::Red, false, 30.f);
	//	DrawDebugLine(World, Location, Location + Direction * 100.f, FColor::Red, true, -1.f, 0, 1.f);
	//	DrawDebugPoint(World, Location, 15.f, FColor::Red, true, -1.f, 0);
	//}

	
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RunningTime += DeltaTime;

}

float AItem::TransformedSin()
{
	return Amplitude * FMath::Sin(RunningTime * TimeConstant);
}

float AItem::TransformedCos()
{
	return Amplitude * FMath::Cos(RunningTime * TimeConstant);
}
