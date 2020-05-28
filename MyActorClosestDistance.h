// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActorClosestDistance.generated.h"

UCLASS()
class THELEARNCPP_API AMyActorClosestDistance : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActorClosestDistance();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//计算函数
	UFUNCTION(BlueprintCallable, Category = "Myfunc")
	float ClosestPairOfPointsDistance(TArray<FVector2D> list, int left, int right);
	//排序
	UFUNCTION(BlueprintCallable, Category = "Myfunc")
	void sortX(TArray<FVector2D> list);
	//两点间距离
	float Distance(FVector2D a, FVector2D b);

};
