// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Pickupable.h>
#include <Equippable.h>
#include <ItemData.h>
#include <Item.h>
#include "ItemSword.generated.h"

UCLASS()
class FASTASLEEP_API AItemSword : public AItem, public IPickupable, public IEquippable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemSword();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable, Category = "Pick Up")
	virtual UItemData* PickUp() override;
	UFUNCTION(BlueprintCallable, Category = "Equip")
	virtual bool Equip() override;
};
