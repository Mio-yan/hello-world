// Fill out your copyright notice in the Description page of Project Settings.

#include "ThelearnCPP.h"
#include "MyPawnforsphere.h"
#include "Camera/CameraComponent.h"
#include "Runtime/Engine/Classes/Components/InputComponent.h"

// Sets default values
AMyPawnforsphere::AMyPawnforsphere()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//����pawn��Ϊ����С�����ҿ���
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	//�����ɸ������ݵ���������
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	//��������Ϳɼ�����
	UCameraComponent* OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("OurCamera"));
	OurVisibleComponent = (USceneComponent*)CreateAbstractDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));

	//������Ϳɼ����󸽼ӵ��������ƫ�Ʋ���ת���
	OurCamera->SetupAttachment(RootComponent);
	OurCamera->SetRelativeLocation(FVector(-250.0f, 0.0f, 250.0f));
	OurCamera->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));
	OurVisibleComponent->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AMyPawnforsphere::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawnforsphere::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//����"Grow"������������������
	float CurrentScale = OurVisibleComponent->GetComponentScale().X;
	if (bGrowing)
	{
		//һ����������������С
		CurrentScale += (DeltaTime * Rate);
	}
	else
	{
		//�������ٶ�����һ��
		CurrentScale -= (DeltaTime*0.5f*Rate);
	}
	//ȷ�����Ὣ����ʼ��С���£���������������С����
	CurrentScale = FMath::Clamp(CurrentScale, Range_Min, Range_Max);
	OurVisibleComponent->SetWorldScale3D(FVector(CurrentScale));
}

// Called to bind functionality to input
void AMyPawnforsphere::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//�ڰ��»��ɿ�"Grow"��ʱ������Ӧ
	InputComponent->BindAction("Grow", IE_Pressed, this, &AMyPawnforsphere::StartGrowing);
	InputComponent->BindAction("Grow", IE_Released, this, &AMyPawnforsphere::StopGrowing);
}

void AMyPawnforsphere::StartGrowing()
{
	bGrowing = true;
}

void AMyPawnforsphere::StopGrowing()
{
	bGrowing = false;
}