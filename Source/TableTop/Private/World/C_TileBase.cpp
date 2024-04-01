// Fill out your copyright notice in the Description page of Project Settings.

#include "World/C_TileBase.h"

AC_TileBase::AC_TileBase()
{
	PrimaryActorTick.bCanEverTick = false;

	SetRootComponent(CreateDefaultSubobject<USceneComponent>("CustomRoot"));

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	MeshComponent->SetupAttachment(RootComponent);
}

void AC_TileBase::OffsetToCube()
{
	const int Q = OffsetCoords.X - (OffsetCoords.Y - (static_cast<int>(OffsetCoords.Y) & 1)) / 2;
	const int R = OffsetCoords.Y;
	const int S = -Q - R;

	CubeCoords = FVector(Q, R, S);
}