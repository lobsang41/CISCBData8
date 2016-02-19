// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Spawner.generated.h"

UCLASS()
class BIGDATAVR_API ASpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BigData")
	float LastHealthRegenerationTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BigData")
	float HealthRegenerationInterval;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BigData")
		FVector MeshProperties;
	// Sets default values for this actor's properties
	ASpawner();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION(BlueprintCallable, Category = "GenerateData")
		void GenerateObjects();

	UFUNCTION(BlueprintCallable, Category = "GenerateData")
		void GenerateObjectsAmount(int32 HowMany, int32 BreakCount, float offset);
	
};
