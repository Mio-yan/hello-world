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

	//�ñ������ΪUPROPERIY,����佫���������ɼ�
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

	//�������
	FVector CurrentVelocity;
	bool bGrowing;
};
