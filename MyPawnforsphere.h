// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPawnforsphere.generated.h"

UCLASS()
class THELEARNCPP_API AMyPawnforsphere : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawnforsphere();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//该变量标记为UPROPERIY,因此其将对虚幻引擎可见
	UPROPERTY(EditAnywhere)
	USceneComponent* OurVisibleComponent;

	UPROPERTY(EditAnywhere,Category="Range")
		float Range_Min;
	UPROPERTY(EditAnywhere,Category="Range")
	float Range_Max;
	UPROPERTY(EditAnywhere,Category="Rate")
	float Rate;

	void StartGrowing();
	void StopGrowing();

	//输入变量
	FVector CurrentVelocity;
	bool bGrowing;
};
