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
	// �⺻�� ����
	ABatteryPickup();

	// WasCollected �Լ��� �������̵� �մϴ�.
	// �׸��� ���⿡�� ���ø����̼�(Implementation)�� ����մϴ�.
	// �������Ʈ ����Ƽ�� �̺�Ʈ�̱� ��������
	void WasCollected_Implementation() override;


	
};
