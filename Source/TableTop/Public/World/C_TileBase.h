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

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "Custom|Grid", meta = (ExposeOnSpawn = true))
	FVector2D Coordinates;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "Custom|Grid")
	TArray<TObjectPtr<AC_TileBase>> Neighbours;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Custom|Grid", meta = (ExposeOnSpawn = true))
	int32 MovementCost = 1;
	
	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "Custom|Grid")
	int32 MovementCostTotal;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "Custom|Grid")
	int32 MovementCostToReachThisTile;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "Custom|Grid")
	int32 MovementCostToReachTarget;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void ResetColor();
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void SetColorOpen();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void SetColorClose();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void SetColorBacktrack();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void SetTileValues();

protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Custom|Tile")
	TObjectPtr<UStaticMeshComponent> MeshComponent;
};
