// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "Pickup.h"
#include "BatteryPickup.generated.h"

/**
 * 
 */
UCLASS()
class BATTERYCOLLECTOR_API ABatteryPickup : public APickup
{
	GENERATED_BODY()

public:
	// 기본값 설정
	ABatteryPickup();

	// WasCollected 함수를 오버라이딩 합니다.
	// 그리고 여기에서 임플멘테이션(Implementation)을 사용합니다.
	// 블루프린트 네이티브 이벤트이기 때문이죠
	void WasCollected_Implementation() override;


	
};
