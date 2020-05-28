// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActorClosestDistance.h"
#include <algorithm>
using namespace std;

TArray<FVector2D> posList3;

float AMyActorClosestDistance::ClosestPairOfPointsDistance(TArray<FVector2D> list, int left, int right)
{//分治法求最短点对

	if ((right - left) == 1)
	{
		float d = Distance(list[left], list[right]);
		if (d > 2)
			return d;
		else
			return 999.999f;
	}
	if (right == left)
	{
		return 999.999f;
	}
	int mid = (right + left) / 2;
	float dis = min(ClosestPairOfPointsDistance(list, left, mid), ClosestPairOfPointsDistance(list, mid + 1, right));

	//合并
	posList3.Empty();
	int minList2 = (int)min(mid + dis, (float)right);
	for (int i = 0; i < minList2; i++)
	{
		if ((mid - i) < dis && (mid - i) > -dis)
		{
			posList3.Add(list[i]);
		}
	}
	posList3.Sort([](const FVector2D &a, const FVector2D &b) {return a.Y < b.Y; });
	for (int i = 0; i < posList3.Num(); i++)
	{
		for (int j = i + 1; j < posList3.Num(); j++)
		{
			float D = posList3[j].Y - posList3[i].Y;
			if (D >= dis || Distance(posList3[i], posList3[j]) < 2)
			{
				break;
			}
			else
			{
				dis = min(dis, Distance(posList3[i], posList3[j]));
			}
		}

	}
	return dis;
}

float AMyActorClosestDistance::Distance(FVector2D a, FVector2D b)
{
	float x = b.X - a.X;
	float y = b.Y - a.Y;
	return sqrt(x * x + y * y);
}

void AMyActorClosestDistance::sortX(TArray<FVector2D> list)
{
	list.Sort([](const FVector2D &a, const FVector2D &b) {return a.X < b.X; });
}

// Sets default values
AMyActorClosestDistance::AMyActorClosestDistance()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActorClosestDistance::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActorClosestDistance::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

