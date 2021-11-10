// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponentC.h"

// Sets default values for this component's properties
UInventoryComponentC::UInventoryComponentC()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

TArray<UInventoryItemC*>& UInventoryComponentC::GetItems()
{
	return Items;
}

UInventoryItemC* UInventoryComponentC::GetItem(const int32 Index) const
{
	if(Index > Items.Num())
	{
		return nullptr;
	}
	else
	{
		return Items[Index];
	}
	
}

bool UInventoryComponentC::AddItem(UInventoryItemC* Item)
{
	Items.Add(Item);
	return true;
}

bool UInventoryComponentC::IsFull()
{
	return Items.Num() >= Size;
}


// Called when the game starts
void UInventoryComponentC::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInventoryComponentC::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

