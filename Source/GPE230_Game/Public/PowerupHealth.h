// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "Powerup.h"
#include "PowerupHealth.generated.h"

/**
 * 
 */
UCLASS()
class GPE230_GAME_API APowerupHealth : public APowerup
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere);
		float healthToHeal = 10.0f;

	UFUNCTION()
		void Apply(class AMazeCharacter* appliedCharacter) override;
};
