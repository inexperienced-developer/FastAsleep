// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <Pickupable.h>
#include <ItemData.h>
#include "InventoryComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FInventoryChanged, UItemData*, itemData, bool, wasAdded);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPickupableInRange, AActor*, itemRef, UItemData*, itemData);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FASTASLEEP_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UFUNCTION(BlueprintCallable, Category = "Pick Up")
	bool CanPickup(AActor* itemRef, UItemData* item);
	UFUNCTION(BlueprintCallable, Category = "Pick Up")
	void AddToInventory(UItemData* item);
	UFUNCTION(BlueprintCallable, Category = "Pick Up")
	void AddToInventoryCloseItem();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UPROPERTY(BlueprintAssignable)
	FPickupableInRange OnPickupableInRange;
	UPROPERTY(BlueprintAssignable)
	FInventoryChanged OnInventoryChanged;

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Inventory")
	TArray<UItemData*> m_items;
	UPROPERTY(BlueprintReadOnly, Category = "Inventory")
	UItemData* m_pickupableInRange;
};
