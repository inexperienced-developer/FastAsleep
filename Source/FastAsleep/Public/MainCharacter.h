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
	UFUNCTION(BlueprintCallable, Category = "State")
	float ToggleCrouch();
	UFUNCTION(BlueprintCallable, Category = "State")
	float ShouldSprint(bool isPressed);
	UFUNCTION(BlueprintCallable, Category = "State")
	void Roll();
	UFUNCTION(BlueprintCallable, Category = "Movement")
	void UseStamina(float amt);
	void RecoverStamina(float deltaTime);

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UFUNCTION(BlueprintCallable, Category = "Bool States")
	bool GetShouldCrouch() { return m_shouldCrouch; }
	UFUNCTION(BlueprintCallable, Category = "Bool States")
	bool GetShouldRun() { return m_shouldRun; }
	UFUNCTION(BlueprintCallable, Category = "Bool States")
	bool GetShouldSprint() { return m_shouldSprint; }

protected:
	UCharacterMovementComponent* m_movement;

	// Stamina settings
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement")
	float m_staminaRecoveryPerSec = 5.0f;
	// Seconds to wait before recovering stamina
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement")
	float m_staminaRecoveryWait = 2.0f;
	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	float m_stamina = 100.0f;
	bool m_recoverStamina;
	float m_staminaRecoveryTimer;

	UPROPERTY(BlueprintReadOnly)
	bool m_shouldCrouch;
	UPROPERTY(BlueprintReadOnly)
	bool m_shouldRun;
	UPROPERTY(BlueprintReadOnly)
	bool m_shouldSprint;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float m_crouchSpeed = 150.0f;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float m_runSpeed = 500.0f;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float m_sprintSpeed = 750.0f;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float m_rollImpulseAmt = 5000.0f;
};
