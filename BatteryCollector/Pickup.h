// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "GameFramework/Actor.h"
#include "Pickup.generated.h"

UCLASS()
class BATTERYCOLLECTOR_API APickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickup();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// �������� Mesh�� ��ȯ����
	FORCEINLINE class UStaticMeshComponent* GetMesh() const { return PickupMesh; }

	// �Լ��� ����� ��������, bIsActive ���¸� ��ȯ���� �ݴϴ�.
	UFUNCTION(BlueprintPure, Category = "Pickup")
		bool IsActive(); // Active = Ȱ������

	// �ٸ�Ŭ�������� �����ϰ� ���� ������ �� �ֵ��� �� �ݴϴ�.
	UFUNCTION(BlueprintCallable, Category = "Pickup")
		void SetActive(bool NewPickupState);

	// �������� �Ծ����� ȣ���ϴ� �Լ�
	UFUNCTION(BlueprintNativeEvent)
	void WasCollected();
	virtual void WasCollected_Implementation();

protected:
	// �������� ��밡������ ǥ���ϴ� �⺻���� True �Դϴ�.
	// �������� ��� �Ұ����Ҷ��� False �Դϴ�.
	bool bIsActive;
	
private:
	// �Ѹ���� ����� StaticMeshComponent
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Pickup", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* PickupMesh;
};
