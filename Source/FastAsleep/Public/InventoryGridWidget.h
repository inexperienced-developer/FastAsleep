// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include <InventoryComponent.h>
#include <Kismet/GameplayStatics.h>
#include "GameFramework/Character.h"
#include "InventoryGridWidget.generated.h"

/**
 * 
 */
UCLASS()
class FASTASLEEP_API UInventoryGridWidget : public UUserWidget
{
	GENERATED_BODY()
	

protected:
	ACharacter* m_player;
	UPROPERTY(BlueprintReadOnly, Category = "Components")
	UInventoryComponent* m_inventory;

protected:
	UFUNCTION(BlueprintCallable, Category = "Utility/Sorting")
	TArray<int32> SortRowColumn(int32 index);
	UFUNCTION(BlueprintNativeEvent, Category = "Events")
	void OnInventoryChanged(UItemData* item, bool wasAdded);
	virtual void OnInventoryChanged_Implementation(UItemData* item, bool wasAdded);

public:
	virtual void NativeConstruct() override;
};
