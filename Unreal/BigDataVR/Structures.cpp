// Fill out your copyright notice in the Description page of Project Settings.

#include "BigDataVR.h"
#include "Structures.h"


// Sets default values for this component's properties
UStructures::UStructures()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UStructures::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UStructures::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

