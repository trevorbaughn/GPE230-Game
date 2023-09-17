// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "VictoryTriggerVolume.generated.h"

/**
 * 
 */
UCLASS()
class GPE230_GAME_API AVictoryTriggerVolume : public ATriggerBox
{
	GENERATED_BODY()
	
public:
	AVictoryTriggerVolume();

	UFUNCTION()
		void CheckActorType(class AActor* OverlappedActor, class AActor* OtherActor);

private:
	void OpenVictoryScreen(class AMazeCharacter* appliedCharacter);
};
