// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "FAUtils.h"
#include "MainCharacter.generated.h"

UCLASS()
class FASTASLEEP_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter();

protected:
	virtual void BeginPlay() override;
	UFUNCTION(BlueprintCallable, Category = "Movement")
	float ToggleCrouch();
	UFUNCTION(BlueprintCallable, Category = "Movement")
	float ShouldSprint(bool isPressed);
	UFUNCTION(BlueprintCallable, Category = "Movement")
	void Roll();
	UFUNCTION(BlueprintCallable, Category = "Movement")
	void UseStamina(float amt);
	void RecoverStamina(float deltaTime);
	virtual void Jump() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	UCharacterMovementComponent* m_movement;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement (Speed)")
	float m_runSpeed = 500.0f;

	// Stamina settings
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Stamina")
	float m_staminaRecoveryPerSec = 5.0f;
	// Seconds to wait before recovering stamina
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Stamina")
	float m_staminaRecoveryWait = 2.0f;
	UPROPERTY(BlueprintReadOnly, Category = "Stamina")
	float m_stamina = 100.0f;
	bool m_recoverStamina;
	float m_staminaRecoveryTimer;

	// Jump Settings
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Stamina (Jump)")
	float m_jumpStamina = 10.0f;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Jump")
	float m_jumpImpulse = 500.0f;

	// Sprint settings
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement (Speed)")
	float m_sprintSpeed = 750.0f;
	UPROPERTY(BlueprintReadOnly, Category = "Bool States")
	bool m_shouldSprint;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Stamina (Sprint)")
	float m_sprintStaminaPerSecond = 10.0f;

	// Roll settings
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Roll")
	float m_rollImpulseAmt = 5000.0f;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Stamina (Roll)")
	float m_rollStamina = 10.0f;
	UPROPERTY(BlueprintReadWrite, Category = "Roll")
	bool m_isRolling;

	// Crouch Settings
	UPROPERTY(BlueprintReadOnly, Category = "Bool States")
	bool m_shouldCrouch;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement (Speed)")
	float m_crouchSpeed = 150.0f;
};
