// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "Powerup.generated.h"

/**
 * 
 */
UCLASS()
class GPE230_GAME_API APowerup : public ATriggerBox
{
	GENERATED_BODY()

public:
	APowerup();

	UPROPERTY(EditAnywhere)
		USoundWave* _pickupSound;

	UFUNCTION()
		void CheckActorType(class AActor* OverlappedActor, class AActor* OtherActor);

	UFUNCTION()
		void DestroySelf();


	virtual void Apply(class AMazeCharacter* appliedCharacter);
};
