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

public:
	AC_GridSystem();

protected:
	UFUNCTION(BlueprintNativeEvent, CallInEditor, Category = "Custom")
	void SpawnTiles();

	UFUNCTION(BlueprintCallable, CallInEditor, Category = "Custom")
	void DestroyTiles();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Custom|Grid")
	TObjectPtr<UClass> TileActor;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "Custom|Grid")
	TMap<FVector2D, AC_TileBase*> TileMap;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Custom|Grid")
	FVector2D GridSize;
	
	UFUNCTION(BlueprintCallable, Category = "Custom|Grid")
	FTransform GetSpawnTransform(int32 IndexX, int32 IndexY, int32& OutIndexX, int32& OutIndexY);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Custom|Grid")
	float HexagonInRadius;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "Custom|Grid")
	float HexagonRowOffset;

	UFUNCTION(BlueprintCallable, Category = "Custom|Grid")
	void GetNeighbours(AC_TileBase* ThisTile);
};
