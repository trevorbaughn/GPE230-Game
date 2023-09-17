// Fill out your copyright notice in the Description page of Project Settings.


#include "VictoryTriggerVolume.h"
#include "MazeCharacter.h"

AVictoryTriggerVolume::AVictoryTriggerVolume()
{
	//On overlap, call CheckActorType
	OnActorBeginOverlap.AddDynamic(this, &AVictoryTriggerVolume::CheckActorType);
}

void AVictoryTriggerVolume::CheckActorType(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor->IsA(AMazeCharacter::StaticClass()))
	{
		OpenVictoryScreen(Cast<AMazeCharacter>(OtherActor));
	}
}

void AVictoryTriggerVolume::OpenVictoryScreen(AMazeCharacter* appliedCharacter)
{
	appliedCharacter->OpenVictoryScreen();
}

