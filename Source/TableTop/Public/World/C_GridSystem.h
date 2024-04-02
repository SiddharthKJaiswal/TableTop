// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C_GridSystem.generated.h"

class AC_TileBase;

UCLASS()
class TABLETOP_API AC_GridSystem : public AActor
{
	GENERATED_BODY()

#pragma region Data
protected:
	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "Custom|Grid")
	TMap<FVector2D, AC_TileBase*> TileMap;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Custom|Grid")
	FVector2D GridSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Custom|Grid")
	float HexagonInRadius;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "Custom|Grid")
	float HexagonRowOffset;
#pragma endregion

#pragma region Functions
public:
	AC_GridSystem();

protected:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, CallInEditor)
	void SpawnTiles();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, CallInEditor)
	void DestroyTiles();
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	FTransform GetSpawnTransform(FVector2D Coords);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void AssignNeighbour();
#pragma endregion
};
