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
	FVector2D OffsetCoords;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "Custom|Grid")
	FVector CubeCoords;

#pragma region Neighbours
	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "Custom|Grid")
	TArray<TObjectPtr<AC_TileBase>> Neighbours;
#pragma endregion

protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Custom|Tile")
	TObjectPtr<UStaticMeshComponent> MeshComponent;

	UFUNCTION(BlueprintCallable, Category = "Custom|Grid")
	void OffsetToCube();
};
