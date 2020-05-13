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

	//将该pawn设为由最小编号玩家控制
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	//创建可附加内容的虚拟根组件
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	//创建相机和可见对象
	UCameraComponent* OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("OurCamera"));
	OurVisibleComponent = (USceneComponent*)CreateAbstractDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));

	//将相机和可见对象附加到根组件，偏移并旋转相机
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

	//根据"Grow"操作处理增长和缩减
	float CurrentScale = OurVisibleComponent->GetComponentScale().X;
	if (bGrowing)
	{
		//一秒内增长到两倍大小
		CurrentScale += (DeltaTime * Rate);
	}
	else
	{
		//以增长速度缩减一半
		CurrentScale -= (DeltaTime*0.5f*Rate);
	}
	//确保不会将至初始大小以下，或者增至两倍大小以上
	CurrentScale = FMath::Clamp(CurrentScale, Range_Min, Range_Max);
	OurVisibleComponent->SetWorldScale3D(FVector(CurrentScale));
}

// Called to bind functionality to input
void AMyPawnforsphere::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//在按下或松开"Grow"键时做出响应
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