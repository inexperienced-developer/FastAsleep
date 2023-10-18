// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "InventoryComponent.h"
#include "UIMain.generated.h"

/**
 * 
 */
UCLASS()
class FASTASLEEP_API UUIMain : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Refs")
	ACharacter* m_player;
	UPROPERTY(BlueprintReadOnly, Category = "Refs")
	UInventoryComponent* m_inventory;

protected:
	UFUNCTION(BlueprintNativeEvent, Category = "Events")
	void OnPickupableInRange(AActor* itemRef, UItemData* item);
	virtual void OnPickupableInRange_Implementation(AActor* itemRef, UItemData* item);


public:
	virtual void NativeConstruct() override;
};
