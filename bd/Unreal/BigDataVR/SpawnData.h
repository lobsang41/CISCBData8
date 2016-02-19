// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Engine/DataTable.h"
#include "ProceduralMeshComponent.h"
#include "SpawnData.generated.h"





USTRUCT(blueprintType)
struct FBig_Data : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
public:
	/*
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FString DATE_TIME;
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
		FString ADDRESS;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
		int32 DISTRICT;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
		FString BEAT;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
		int32 GRID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
		FString CRIME_DESCR;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
		int32 UCR_NCIC_CODE;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
		float LATITUDE;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
		float LONGITUDE;
};



UCLASS()
class BIGDATAVR_API ASpawnData : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnData();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;


	UFUNCTION(BlueprintCallable, Category = "GenerateData")
	void Generate(float x, float y);

	UFUNCTION(BlueprintCallable, Category = "GenerateData")
	void GenerateTestMesh(int32 times);
	
};
