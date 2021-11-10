// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "InventoryItemC.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class GE_PZ_API UInventoryItemC : public UObject
{
public:
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	FName Title;

	UPROPERTY(BlueprintReadWrite)
	UTexture2D* ItemIcon;

	UInventoryItemC();
	explicit UInventoryItemC(FName Title);
};
