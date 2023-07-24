// Fill out your copyright notice in the Description page of Project Settings.


#include "PowerupHealth.h"
#include "HealthComponent.h"
#include "MazeCharacter.h"

void APowerupHealth::Apply(AMazeCharacter* appliedCharacter)
{
	UE_LOG(LogTemp, Log, TEXT("Player healed %f."), healthToHeal);

	//take damage on the health component of affected MazeCharacter
	appliedCharacter->GetComponentByClass<UHealthComponent>()->HealDamage(healthToHeal);
}
