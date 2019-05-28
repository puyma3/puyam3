// Fill out your copyright notice in the Description page of Project Settings.

#include "BatteryCollector.h"
#include "SpawnVolume.h"
#include "Kismet/KismetMathLibrary.h"
#include "Pickup.h"

// Sets default values
ASpawnVolume::ASpawnVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// SpawnVolume �� ǥ���ϱ� ���ؼ� BoxComponent ����
	WhereToSpawn = CreateDefaultSubobject<UBoxComponent>(TEXT("WhereToSpawn"));
	RootComponent = WhereToSpawn;

	// �����ۻ��� �ּ�/�ִ� �ʱⰪ �����ϱ�
	SpawnDelayRangeLow = 1.0f;
	SpawnDelayRangeHigh = 4.5f;

}

// Called when the game starts or when spawned
void ASpawnVolume::BeginPlay()
{
	Super::BeginPlay();
	// FRandRange : �������� ������ ���� �÷�Ʈ�� ��ȯ�ϴ� �Լ�

	SpawnDelay = FMath::FRandRange(SpawnDelayRangeLow, SpawnDelayRangeHigh);
	GetWorldTimerManager().SetTimer(SpawnTimer, this, &ASpawnVolume::SpawnPickup, SpawnDelay, false);
	// �ڵ��� �����ٰ�. SetTimerŬ�󽺸� ���ؼ�,SpawnPickup�� ���ε��ϰ�, SpawnDelay ��ŭ�� �ð��� �帣�� ȣ���ϵ��� �մϴ�. �ݺ����� �ʵ���
	
}

// Called every frame
void ASpawnVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FVector ASpawnVolume::GetRandomPointInVolume()
{
	FVector SpawnOrigin = WhereToSpawn->Bounds.Origin;
	FVector SpawnExtent = WhereToSpawn->Bounds.BoxExtent;

	return UKismetMathLibrary::RandomPointInBoundingBox(SpawnOrigin, SpawnExtent);
}

void ASpawnVolume::SpawnPickup()
{
	// ������ ���� �����Ǿ� �ִٸ�
	if (WhatToSpawn != NULL)
	{
		// ���尡 ��ȿ���� Ȯ���� ���Դϴ�.
		UWorld* const World = GetWorld();
		if (World)
		{
			// ������ ������ ���ϰ�
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this; // Owner : ������
			SpawnParams.Instigator = Instigator; // SpawnParams: �Ű����� ���� , Spawn: ��

			//����� ��ġ�� ������ ��ġ�� ��
			FVector SpawnLocation = GetRandomPointInVolume();

			// ������ �����ۿ� ������ �����̼� ���� �־���
			FRotator SpawnRotation;
			SpawnRotation.Yaw = FMath::FRand() * 360.0f;
			SpawnRotation.Pitch = FMath::FRand() * 360.0f;
			SpawnRotation.Roll = FMath::FRand() * 360.0f;

			// �������� �����մϴ�.
			APickup* const SpawnedPickup = World->SpawnActor<APickup>(WhatToSpawn, SpawnLocation, SpawnRotation, SpawnParams);

			SpawnDelay = FMath::FRandRange(SpawnDelayRangeLow, SpawnDelayRangeHigh);
			GetWorldTimerManager().SetTimer(SpawnTimer, this, &ASpawnVolume::SpawnPickup, SpawnDelay, false);
			// �ڵ��� �����ٰ�. SetTimerŬ�󽺸� ���ؼ�,SpawnPickup�� ���ε��ϰ�, SpawnDelay ��ŭ�� �ð��� �帣�� ȣ���ϵ��� �մϴ�. �ݺ����� �ʵ���
		}
	}
}