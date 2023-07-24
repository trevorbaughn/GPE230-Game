// Fill out your copyright notice in the Description page of Project Settings.

#include "Powerup.h"
#include "MazeCharacter.h"


APowerup::APowerup()
{
	//On overlap, call CheckActorType
	OnActorBeginOverlap.AddDynamic(this, &APowerup::CheckActorType);
}

void APowerup::CheckActorType(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor->IsA(AMazeCharacter::StaticClass()))
	{
		Apply(Cast<AMazeCharacter>(OtherActor));
		DestroySelf();
	}
}


void APowerup::DestroySelf()
{
	this->Destroy();
}

void APowerup::Apply(AMazeCharacter* appliedCharacter)
{
}

