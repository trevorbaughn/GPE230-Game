// Fill out your copyright notice in the Description page of Project Settings.
#include "LockAndKey.h"
#include "MazeCharacter.h"
#include "Sound/SoundWave.h"
#include "Kismet/GameplayStatics.h"


ALockAndKey::ALockAndKey()
{
	//On overlap, call CheckActorType
	OnActorBeginOverlap.AddDynamic(this, &ALockAndKey::CheckActorType);
}

/// <summary>
/// Check if other actor is a MazeCharacter.  If it is, open the door.
/// </summary>
/// <param name="OverlappedActor"></param>
/// <param name="OtherActor"></param>
void ALockAndKey::CheckActorType(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor->IsA(AMazeCharacter::StaticClass())) 
	{
		OpenTheDoor();
	}
		
}

/// <summary>
/// Destroy the door.
/// </summary>
void ALockAndKey::OpenTheDoor()
{
	
	UGameplayStatics::PlaySound2D(this, _openDoorSound, 1.0, 1.0, 0.0);

	this->Destroy();
}
