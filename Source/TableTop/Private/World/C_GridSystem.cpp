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

void AC_GridSystem::DestroyTiles_Implementation()
{
	for (const TTuple<UE::Math::TVector2<double>, AC_TileBase*> NewTile : TileMap)
	{
		if(NewTile.Value != nullptr)
		{
			NewTile.Value->Destroy();
		}
	}
	TileMap.Empty();
}

void AC_GridSystem::FindDistanceBetweenTiles_Implementation()
{
	
}

FTransform AC_GridSystem::GetSpawnTransform_Implementation(FVector2D Coords)
{
	return GetActorTransform();
}

void AC_GridSystem::AssignNeighbour_Implementation()
{
}
