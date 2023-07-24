// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Powerup.h"
#include "PowerupScore.generated.h"

/**
 * 
 */
UCLASS()
class GPE230_GAME_API APowerupScore : public APowerup
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere);
		int scoreToAdd;

	UFUNCTION()
		void Apply(class AMazeCharacter* appliedCharacter) override;
};
