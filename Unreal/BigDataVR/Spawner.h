// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/DataTable.h"
#include "GameFramework/Actor.h"
#include "Spawner.generated.h"



/** Yelp Base data */

USTRUCT(blueprintType)
struct FGameObjectTable : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
		/** Full Path of Blueprint */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BigDataS6L")
		FString UserId;

	/** Category of GamePlay Object */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BigDataS6L")
		int32 Rating;

	/** Scriptable Use Code */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BigDataS6L")
		FString BusinessId;
};


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

	UFUNCTION(BlueprintCallable, Category = "GenerateData")
		void GenerateObjectsAmountWithTransform(int32 HowMany, int32 BreakCount, float offset, FTransform transform);

	UFUNCTION(BlueprintCallable, Category = "GenerateData")
		void GenerateSingleObjectWithTransform(float offset, FTransform transform);
private:
};
