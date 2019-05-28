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

	// SpawnVolume 을 표시하기 위해서 BoxComponent 생성
	WhereToSpawn = CreateDefaultSubobject<UBoxComponent>(TEXT("WhereToSpawn"));
	RootComponent = WhereToSpawn;

	// 아이템생성 최소/최대 초기값 설정하기
	SpawnDelayRangeLow = 1.0f;
	SpawnDelayRangeHigh = 4.5f;

}

// Called when the game starts or when spawned
void ASpawnVolume::BeginPlay()
{
	Super::BeginPlay();
	// FRandRange : 범위내의 랜덤한 값을 플로트로 변환하는 함수

	SpawnDelay = FMath::FRandRange(SpawnDelayRangeLow, SpawnDelayRangeHigh);
	GetWorldTimerManager().SetTimer(SpawnTimer, this, &ASpawnVolume::SpawnPickup, SpawnDelay, false);
	// 핸들을 가져다가. SetTimer클라스를 위해서,SpawnPickup에 바인딩하고, SpawnDelay 만큼의 시간이 흐르면 호출하도록 합니다. 반복하지 않도록
	
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
	// 생성될 것이 설정되어 있다면
	if (WhatToSpawn != NULL)
	{
		// 월드가 유효한지 확인할 것입니다.
		UWorld* const World = GetWorld();
		if (World)
		{
			// 생성할 범위를 정하고
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this; // Owner : 소유자
			SpawnParams.Instigator = Instigator; // SpawnParams: 매개변수 생성 , Spawn: 알

			//만드는 위치에 랜덤한 위치를 고름
			FVector SpawnLocation = GetRandomPointInVolume();

			// 생성한 아이템에 랜덤한 로테이션 값을 넣어줌
			FRotator SpawnRotation;
			SpawnRotation.Yaw = FMath::FRand() * 360.0f;
			SpawnRotation.Pitch = FMath::FRand() * 360.0f;
			SpawnRotation.Roll = FMath::FRand() * 360.0f;

			// 아이템을 생성합니다.
			APickup* const SpawnedPickup = World->SpawnActor<APickup>(WhatToSpawn, SpawnLocation, SpawnRotation, SpawnParams);

			SpawnDelay = FMath::FRandRange(SpawnDelayRangeLow, SpawnDelayRangeHigh);
			GetWorldTimerManager().SetTimer(SpawnTimer, this, &ASpawnVolume::SpawnPickup, SpawnDelay, false);
			// 핸들을 가져다가. SetTimer클라스를 위해서,SpawnPickup에 바인딩하고, SpawnDelay 만큼의 시간이 흐르면 호출하도록 합니다. 반복하지 않도록
		}
	}
}