// Fill out your copyright notice in the Description page of Project Settings.


#include "Killable.h"

// Add default functionality here for any IKillable functions that are not pure virtual.

void IKillable::Die()
{
	UE_LOG(LogTemp, Log, TEXT("Something died..."))
}
