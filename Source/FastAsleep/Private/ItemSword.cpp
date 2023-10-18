// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemSword.h"

// Sets default values
AItemSword::AItemSword()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AItemSword::BeginPlay()
{
	Super::BeginPlay();
	
}

UItemData* AItemSword::PickUp()
{
	return m_itemData;
}

bool AItemSword::Equip()
{
	return true;
}

// Called every frame
void AItemSword::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

