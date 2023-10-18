// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryGridWidget.h"

void UInventoryGridWidget::OnInventoryChanged_Implementation(UItemData* item, bool wasAdded)
{
}

void UInventoryGridWidget::NativeConstruct()
{
	Super::NativeConstruct();
	m_player = Cast<ACharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	if (m_player == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Player is null."));
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Player is null."));
		return;
	}
	m_inventory = m_player->GetComponentByClass<UInventoryComponent>();
	if (m_inventory == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Inventory is null."));
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Inventory is null."));
		return;
	}
	m_inventory->OnInventoryChanged.AddDynamic(this, &UInventoryGridWidget::OnInventoryChanged);
}

TArray<int32> UInventoryGridWidget::SortRowColumn(int32 index)
{
	int32 row;
	int32 col;
	// Assuming our max inventory is 16
	row = index % 4;
	col = index / 4;
	TArray<int32> res = { row, col };
	return res;
}
