// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Killable.h"
#include "Blueprint/UserWidget.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"

#include "MazeCharacter.generated.h"

UCLASS()
class GPE230_GAME_API AMazeCharacter : public ACharacter, public IKillable
{
	GENERATED_BODY()

private:
	FTimerHandle openGameOverTimerHandle;

	

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
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> _gameOverScreenTemplate;
	UUserWidget* _gameOverScreenInstance;
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> _victoryScreenTemplate;
	UUserWidget* _victoryScreenInstance;
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> _HUDTemplate;
	UUserWidget* _HUDInstance;
	
protected:
	/// <summary>
	/// Controller that manages this character
	/// </summary>
	APlayerController* _controller;

public:
	// Sets default values for this character's properties
	AMazeCharacter();
	virtual void OpenVictoryScreen();

protected:
	UFUNCTION(BlueprintCallable)
		virtual void OpenGameOverScreen();

	UFUNCTION(BlueprintCallable)
		virtual void PauseGameplay(bool isPaused);
	UFUNCTION(BlueprintCallable)
		virtual void ShowMouseCursor(bool isShown);

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
	virtual void OpenHUD();
	UFUNCTION(BlueprintCallable)
		void ActivateStunParticleSystem();

};
