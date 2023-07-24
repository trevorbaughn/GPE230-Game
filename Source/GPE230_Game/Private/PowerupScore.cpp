// Fill out your copyright notice in the Description page of Project Settings.

#include "PowerupScore.h"
#include "ScoreableComponent.h"
#include "MazeCharacter.h"

void APowerupScore::Apply(AMazeCharacter* appliedCharacter)
{
	UE_LOG(LogTemp, Log, TEXT("Player score added: %f."), scoreToAdd);

	//take damage on the health component of affected MazeCharacter
	appliedCharacter->GetComponentByClass<UScoreableComponent>()->score += scoreToAdd;
}