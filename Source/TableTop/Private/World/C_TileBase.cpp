// Fill out your copyright notice in the Description page of Project Settings.

#include "World/C_TileBase.h"

AC_TileBase::AC_TileBase()
{
	PrimaryActorTick.bCanEverTick = false;

	SetRootComponent(CreateDefaultSubobject<USceneComponent>("CustomRoot"));

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	MeshComponent->SetupAttachment(RootComponent);
}

void AC_TileBase::ResetColor_Implementation()
{
}

void AC_TileBase::SetColorOpen_Implementation()
{
}

void AC_TileBase::SetColorClose_Implementation()
{
}

void AC_TileBase::SetColorBacktrack_Implementation()
{
}

void AC_TileBase::SetTileValues_Implementation()
{
}
