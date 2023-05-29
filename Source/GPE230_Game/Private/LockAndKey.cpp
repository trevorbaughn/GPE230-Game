// Fill out your copyright notice in the Description page of Project Settings.

#include "MazeCharacter.h"
#include "LockAndKey.h"

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
	this->Destroy();
}
