// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C_GridSystem.generated.h"

#pragma region ForwardDeclarations
class AC_TileBase;
#pragma endregion

#pragma region Structs
#pragma endregion

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

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Custom|Grid")
	float HexagonInRadius;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Custom|Grid")
	TArray<AC_TileBase*> OpenList;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Custom|Grid")
	TArray<AC_TileBase*> ClosedList;
#pragma endregion

#pragma region Functions
public:
	AC_GridSystem();

protected:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, CallInEditor)
	void SpawnTiles();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, CallInEditor)
	void DestroyTiles();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, CallInEditor)
	void FindDistanceBetweenTiles();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	FTransform GetSpawnTransform(FVector2D Coords);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void AssignNeighbour();
#pragma endregion
};
