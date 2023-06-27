// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GPE230_GAME_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	//max health of actor
	UPROPERTY(EditAnywhere)
		float maxHealth;

public:
	//current actor health
	float _currentHealth;

private:
	UPROPERTY(EditAnywhere)
		bool _isDead = false;
	

public:	
	// Sets default values for this component's properties
	UHealthComponent();
	virtual float TakeDamage(float DamageAmount);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	//mimic the TakeDamage function on ACharacter class.
	
	virtual void Die();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
