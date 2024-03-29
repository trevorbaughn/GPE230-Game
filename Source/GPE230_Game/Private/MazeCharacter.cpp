// Fill out your copyright notice in the Description page of Project Settings.



#include "MazeCharacter.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include <Animation/AnimData/AnimDataModel.h>

// Sets default values
AMazeCharacter::AMazeCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}



void AMazeCharacter::OpenVictoryScreen()
{
	_victoryScreenInstance->AddToViewport();
	PauseGameplay(true);
	ShowMouseCursor(true);
}

void AMazeCharacter::OpenGameOverScreen()
{
	_gameOverScreenInstance->AddToViewport();
	PauseGameplay(true);
	ShowMouseCursor(true);
}

void AMazeCharacter::PauseGameplay(bool isPaused)
{
	_controller->SetPause(isPaused);
}

void AMazeCharacter::ShowMouseCursor(bool isShown)
{
	_controller->bShowMouseCursor = isShown;
}

// Called when the game starts or when spawned
void AMazeCharacter::BeginPlay()
{
	Super::BeginPlay();

	_controller = Cast<APlayerController>(GetController());

	_gameOverScreenInstance = CreateWidget(GetWorld(), _gameOverScreenTemplate);
	_victoryScreenInstance = CreateWidget(GetWorld(), _victoryScreenTemplate);
	_HUDInstance = CreateWidget(GetWorld(), _HUDTemplate);

	OpenHUD();
}

// Called every frame
void AMazeCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMazeCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveFB"), this, &AMazeCharacter::MoveFB);
	PlayerInputComponent->BindAxis(TEXT("MoveLR"), this, &AMazeCharacter::MoveLR);
	PlayerInputComponent->BindAxis(TEXT("Rotate"), this, &AMazeCharacter::Rotate);
	//PlayerInputComponent->BindAction(TEXT("Run"), IE_Pressed, this, &AMazeCharacter::SetRunSpeed);
	//PlayerInputComponent->BindAction(TEXT("Run"), IE_Released, this, &AMazeCharacter::SetWalkSpeed);

}

void AMazeCharacter::MoveFB(float value)
{
	AddMovementInput(GetActorForwardVector(), value * moveSpeed);
}

void AMazeCharacter::MoveLR(float value)
{
	AddMovementInput(-GetActorRightVector(), value * moveSpeed);
}

void AMazeCharacter::Rotate(float value)
{
	AddControllerYawInput(value * rotationSpeed);
}

void AMazeCharacter::SetRunSpeed()
{
	moveSpeed = runSpeed;
}

void AMazeCharacter::SetWalkSpeed()
{
	
	moveSpeed = walkSpeed;
}

void AMazeCharacter::Die()
{
	moveSpeed = 0;
	rotationSpeed = 0;
	
	GetMesh()->PlayAnimation(_deathAnim, false);

	//Runs OpenGameOverScreen after the length of _deathAnim
	GetWorldTimerManager().SetTimer(openGameOverTimerHandle, this, &AMazeCharacter::OpenGameOverScreen, _deathAnim->GetPlayLength(), false);
}

void AMazeCharacter::OpenHUD()
{
	_HUDInstance->AddToViewport();
}

void AMazeCharacter::ActivateStunParticleSystem()
{
	if (_stunSystem)
	{
		USceneComponent* AttachComp = GetDefaultAttachComponent();

		//attaches location of particle spawn to MazeCharacter pos
		UNiagaraComponent* NiagaraComp = UNiagaraFunctionLibrary::SpawnSystemAttached(_stunSystem, AttachComp, NAME_None,
			FVector(0), FRotator(0), EAttachLocation::Type::KeepRelativeOffset, true);

		NiagaraComp->Activate();
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Player attempted to use the stun ability, but no template particle system was found."));
	}
}
