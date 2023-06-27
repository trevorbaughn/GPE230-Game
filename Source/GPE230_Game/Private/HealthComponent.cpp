// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"
#include "MazeCharacter.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	_currentHealth = maxHealth;

	TakeDamage(10.0f);
	
}

/// <summary>
/// Take Damage.
/// </summary>
/// <param name="DamageAmount"></param>
/// <param name="DamageEvent"></param>
/// <param name="EventInstigator"></param>
/// <param name="DamageCauser"></param>
/// <returns></returns>
float UHealthComponent::TakeDamage(float DamageAmount)
{
	if (!_isDead)
	{
		//Subtract incoming damage
		_currentHealth -= DamageAmount;

		UE_LOG(LogTemp, Log, TEXT("Player took %f damage.  %f health remaining."), DamageAmount, _currentHealth);

		//if health is less than/or 0, die.
		if (_currentHealth <= 0)
			Die();

		return DamageAmount;
	}
	else
		return 0;

	
}

void UHealthComponent::Die()
{
	_isDead = true;
	_currentHealth = 0;
	
	//calls die function on owner if it implements IKillable, otherwise errors
	Cast<IKillable>(GetOwner())->Die();

	//TODO: Trigger game over and prompt restart
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

