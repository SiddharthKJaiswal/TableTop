// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C_TileBase.generated.h"

UCLASS()
class TABLETOP_API AC_TileBase : public AActor
{
	GENERATED_BODY()

public:
	AC_TileBase();

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "Custom|Grid")
	FVector TilePosition;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "Custom|Grid")
	TObjectPtr<AC_TileBase> NeighbourNorth = nullptr;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "Custom|Grid")
	TObjectPtr<AC_TileBase> NeighbourEast = nullptr;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "Custom|Grid")
	TObjectPtr<AC_TileBase> NeighbourSouthEast = nullptr;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "Custom|Grid")
	TObjectPtr<AC_TileBase> NeighbourSouth = nullptr;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "Custom|Grid")
	TObjectPtr<AC_TileBase> NeighbourWest = nullptr;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "Custom|Grid")
	TObjectPtr<AC_TileBase> NeighbourNorthWest = nullptr;

protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Custom|Tile")
	TObjectPtr<UStaticMeshComponent> MeshComponent;
};
