// Fill out your copyright notice in the Description page of Project Settings.


#include "UIMain.h"
void UUIMain::NativeConstruct()
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

	m_inventory->OnPickupableInRange.AddDynamic(this, &UUIMain::OnPickupableInRange);
}


