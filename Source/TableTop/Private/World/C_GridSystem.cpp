// Fill out your copyright notice in the Description page of Project Settings.

#include "World/C_GridSystem.h"
#include "World/C_TileBase.h"

AC_GridSystem::AC_GridSystem()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AC_GridSystem::SpawnTiles_Implementation()
{
}

void AC_GridSystem::DestroyTiles()
{
	for (const TTuple<UE::Math::TVector2<double>, AC_TileBase*> NewTile : TileMap)
	{
		NewTile.Value->Destroy();
	}
	TileMap.Empty();
}

FTransform AC_GridSystem::GetSpawnTransform(int32 IndexX, int32 IndexY, int32& OutIndexX, int32& OutIndexY)
{
	FVector SpawnPosition = GetActorLocation();

	OutIndexX = IndexX;
	OutIndexY = IndexY;

	if (IndexX % 2 == 1)
	{
		SpawnPosition.X += IndexX * 2.0f * HexagonInRadius + HexagonInRadius * -1.0f;
	}
	else
	{
		SpawnPosition.X += IndexX * 2.0f * HexagonInRadius;
	}
	SpawnPosition.Y += IndexY * 1.5f * (HexagonInRadius * 2.0f / FMath::Sqrt(3.0f));

	FTransform SpawnTransform = GetActorTransform();
	SpawnTransform.SetLocation(SpawnPosition);
	return SpawnTransform;
}

void AC_GridSystem::GetNeighbours(AC_TileBase* ThisTile)
{
	int X = ThisTile->OffsetCoords.X;
	if (X % 2 == 0)
	{
		ThisTile->CubeCoords = FVector(10, 10, 10);
		//ThisTile->NeighbourWest = TileMap.Find(FVector2D(ThisTile->CubeCoords.X, ThisTile->CubeCoords.X - 1));
	}
}
