// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

bool UInventoryComponent::CanPickup(AActor* itemRef, UItemData* item)
{
	m_pickupableInRange = item;
	OnPickupableInRange.Broadcast(itemRef, item);
	return item != nullptr;
}

void UInventoryComponent::AddToInventory(UItemData* item)
{
	m_items.Add(item);
	OnInventoryChanged.Broadcast(item, true);
}

void UInventoryComponent::AddToInventoryCloseItem()
{
	if (m_pickupableInRange == nullptr) return;
	AddToInventory(m_pickupableInRange);
}


// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

