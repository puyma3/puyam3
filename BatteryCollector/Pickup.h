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

	// 아이템의 Mesh를 반환해줌
	FORCEINLINE class UStaticMeshComponent* GetMesh() const { return PickupMesh; }

	// 함수의 기능이 무엇인지, bIsActive 상태를 반환시켜 줍니다.
	UFUNCTION(BlueprintPure, Category = "Pickup")
		bool IsActive(); // Active = 활동적인

	// 다른클래서에서 안전하게 값을 변경할 수 있도록 해 줍니다.
	UFUNCTION(BlueprintCallable, Category = "Pickup")
		void SetActive(bool NewPickupState);

	// 아이템을 먹었을때 호출하는 함수
	UFUNCTION(BlueprintNativeEvent)
	void WasCollected();
	virtual void WasCollected_Implementation();

protected:
	// 아이템이 사용가능함을 표현하는 기본값은 True 입니다.
	// 아이템이 사용 불가능할때는 False 입니다.
	bool bIsActive;
	
private:
	// 겉모습을 담당할 StaticMeshComponent
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Pickup", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* PickupMesh;
};
