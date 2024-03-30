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

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Custom|Tile")
	TObjectPtr<UStaticMeshComponent> MeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Custom|Tile")
	TObjectPtr<UStaticMesh> DefaultTileMesh;
};
