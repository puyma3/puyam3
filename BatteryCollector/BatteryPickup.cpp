// Fill out your copyright notice in the Description page of Project Settings.


#include "BatteryPickup.h"

ABatteryPickup::ABatteryPickup()
{
	GetMesh()->SetSimulatePhysics(true);
}

void ABatteryPickup::WasCollected_Implementation()
{
	// 베이스 픽업 스크립트 사용. 부모 함수를 호출합니다.
	Super::WasCollected_Implementation();

	// 베터리 아이템 파괴하기
	Destroy();
}