// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ReloadableInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UReloadableInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GE_PZ_API IReloadableInterface
{
	GENERATED_BODY()
public:
	virtual bool CanReload() = 0;
	virtual void Reload() = 0;
};
