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

	// WhereToSpawn ���� ��ȯ���� �ݴϴ�.
	FORCEINLINE class UBoxComponent* GetWhereToSpawn() const { return WhereToSpawn; }

	//�ڽ� ������Ʈ �������� ������ ��ǥ�� ��ȯ�մϴ�.
	UFUNCTION(BlueprintPure, Category = "Spawning")
		FVector GetRandomPointInVolume();

protected:
	// The Pickup to spawn. �Ⱦ��� �ڽ��� ����.
	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<class APickup> WhatToSpawn;

	FTimerHandle SpawnTimer;

	//������ �ּҽð� ����
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Spawning")
	float SpawnDelayRangeLow; // Range : ����

	//������ �ִ�ð� ����
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Spawning")
	float SpawnDelayRangeHigh;
	

private:
	//������ ���� ��ġ�� ������ �ڽ�
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning", meta = (AllowPrivateAccess = "true"))
		class UBoxComponent* WhereToSpawn;

	// �� ������ ������ �ٷ�. private �����̶� �ٸ�Ŭ���������� ȣ���� �� ����.
	void SpawnPickup();

	// ���� ������ ���� ������ ��
	float SpawnDelay;
};
