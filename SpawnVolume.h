// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnVolume.generated.h"

UCLASS()
class BATTERYCOLLECTOR_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnVolume();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// WhereToSpawn 값을 반환시켜 줍니다.
	FORCEINLINE class UBoxComponent* GetWhereToSpawn() const { return WhereToSpawn; }

	//박스 컴포넌트 볼륨속의 랜덤한 좌표를 반환합니다.
	UFUNCTION(BlueprintPure, Category = "Spawning")
		FVector GetRandomPointInVolume();

protected:
	// The Pickup to spawn. 픽업의 자식을 낳다.
	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<class APickup> WhatToSpawn;

	FTimerHandle SpawnTimer;

	//생성시 최소시간 지연
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Spawning")
	float SpawnDelayRangeLow; // Range : 범위

	//생성시 최대시간 지연
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Spawning")
	float SpawnDelayRangeHigh;
	

private:
	//아이템 스폰 위치를 지정할 박스
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning", meta = (AllowPrivateAccess = "true"))
		class UBoxComponent* WhereToSpawn;

	// 새 아이템 생성을 다룸. private 형식이라 다른클래스에서는 호출할 수 없음.
	void SpawnPickup();

	// 현재 아이템 생성 딜레이 값
	float SpawnDelay;
};
