// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"
#include "MazeCharacter.h"


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	_currentHealth = maxHealth;
	
}

float UHealthComponent::GetMaxHealth()
{
	return maxHealth;
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

/// <summary>
/// Heal damage.
/// </summary>
/// <param name="HealAmount"></param>
/// <returns></returns>
float UHealthComponent::HealDamage(float HealAmount)
{
	if (!_isDead)
	{
		UE_LOG(LogTemp, Log, TEXT("Player took %f damage.  %f health remaining."), HealAmount, _currentHealth);

		//if health is greater than/or maxHealth, clamp.
		if ((_currentHealth + HealAmount) >= maxHealth) 
		{
			_currentHealth = maxHealth;
		}
		else 
		{
			//Add incoming health
			_currentHealth += HealAmount;
		}
			

		return HealAmount;
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



