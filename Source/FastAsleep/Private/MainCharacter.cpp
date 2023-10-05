// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	m_movement = Cast<UCharacterMovementComponent>(GetMovementComponent());
	m_staminaRecoveryTimer = m_staminaRecoveryWait;
}

float AMainCharacter::ToggleCrouch()
{
	bool shouldCrouch = !m_shouldCrouch;
	m_shouldCrouch = shouldCrouch;
	if (shouldCrouch)
	{
		return m_crouchSpeed;
	}
	return m_runSpeed;
}

float AMainCharacter::ShouldSprint(bool isPressed)
{
	if (m_shouldCrouch) return m_crouchSpeed;
	m_shouldSprint = isPressed && m_stamina > 0;
	FString msg = FString::Printf(TEXT("Should sprint: %f"), m_shouldSprint);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, msg);
	if (isPressed)
	{
		if (m_stamina <= 0) return m_runSpeed;
		return m_sprintSpeed;
	}
	return m_runSpeed;
}

void AMainCharacter::Roll()
{
	if (m_stamina < 10) return;
	if (m_movement == nullptr) return;
	// Figure out how much to use
	UseStamina(10);
	FVector fwd = GetActorForwardVector();
	m_movement->AddImpulse(fwd * m_rollImpulseAmt, true);
}

void AMainCharacter::UseStamina(float amt)
{
	if (m_stamina <= 0) return;
	m_staminaRecoveryTimer = m_staminaRecoveryWait;
	m_recoverStamina = false;
	m_stamina -= amt;
	m_stamina = FMath::Clamp(m_stamina, 0, 100);
}

void AMainCharacter::RecoverStamina(float deltaTime)
{
	if (m_recoverStamina)
	{
		m_staminaRecoveryTimer = m_staminaRecoveryWait;
		float recoveryRate = deltaTime * m_staminaRecoveryPerSec;
		m_stamina += recoveryRate;
		m_stamina = FMath::Clamp(m_stamina, 0, 100);
		m_recoverStamina = m_stamina < 100;
	}
	else
	{
		m_recoverStamina = m_stamina < 100 && m_staminaRecoveryTimer <= 0;
		m_staminaRecoveryTimer -= deltaTime;
	}
}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	RecoverStamina(DeltaTime);
	if (m_shouldSprint)
	{
		UseStamina(10 * DeltaTime);
		if (m_stamina <= 0)
		{
			m_movement->MaxWalkSpeed = ShouldSprint(false);
		}
	}
}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

