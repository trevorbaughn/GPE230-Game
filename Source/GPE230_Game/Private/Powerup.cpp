// Fill out your copyright notice in the Description page of Project Settings.
#include "Sound/SoundWave.h"
#include "Kismet/GameplayStatics.h"
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
		UGameplayStatics::PlaySound2D(this, _pickupSound, 1.0, 1.0, 0.0);
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

