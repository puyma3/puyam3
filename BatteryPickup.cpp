// Fill out your copyright notice in the Description page of Project Settings.


#include "BatteryPickup.h"

ABatteryPickup::ABatteryPickup()
{
	GetMesh()->SetSimulatePhysics(true);
}

void ABatteryPickup::WasCollected_Implementation()
{
	// ���̽� �Ⱦ� ��ũ��Ʈ ���. �θ� �Լ��� ȣ���մϴ�.
	Super::WasCollected_Implementation();

	// ���͸� ������ �ı��ϱ�
	Destroy();
}