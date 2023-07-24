// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Killable.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"

#include "MazeCharacter.generated.h"

UCLASS()
class GPE230_GAME_API AMazeCharacter : public ACharacter, public IKillable
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
		float runSpeed;
	UPROPERTY(EditAnywhere)
		float walkSpeed;

	UPROPERTY(EditAnywhere)
		float moveSpeed = walkSpeed;
	UPROPERTY(EditAnywhere)
		float rotationSpeed;
	UPROPERTY(EditAnywhere)
		UAnimSequence* _deathAnim;
	UPROPERTY(EditAnywhere)
		UNiagaraSystem* _stunSystem;
	
	

public:
	// Sets default values for this character's properties
	AMazeCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;



private:
	void MoveFB(float value);
	void MoveLR(float value);
	void Rotate(float value);
	void SetRunSpeed();
	void SetWalkSpeed();
	void Die() override;
	UFUNCTION(BlueprintCallable)
		void ActivateStunParticleSystem();

};
