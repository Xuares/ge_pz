// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryItemC.h"
#include "Components/ActorComponent.h"
#include "InventoryComponentC.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GE_PZ_API UInventoryComponentC : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponentC();

	UPROPERTY(EditAnywhere)
	TArray<UInventoryItemC*> Items;

	UPROPERTY(BlueprintReadWrite)
	int32 Size = 10;

	UFUNCTION(BlueprintCallable)
	TArray<UInventoryItemC*>& GetItems();

	UFUNCTION(BlueprintCallable)
	UInventoryItemC* GetItem(const int32 Index) const;

	UFUNCTION(BlueprintCallable)
	bool AddItem(UInventoryItemC* Item);

	UFUNCTION(BlueprintCallable)
	bool IsFull();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
