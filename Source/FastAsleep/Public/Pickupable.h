// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ItemData.h"
#include "Pickupable.generated.h"

// This class does not need to be modified.
UINTERFACE(BlueprintType)
class UPickupable : public UInterface
{
	GENERATED_BODY()
};

class FASTASLEEP_API IPickupable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual UItemData* PickUp();
};


