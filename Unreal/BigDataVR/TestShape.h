// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "Engine.h"
#include "TestShape.generated.h"



UCLASS()
class BIGDATAVR_API ATestShape : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestShape();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UProceduralMeshComponent* mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, transient, Category = "BigData")
		UTextRenderComponent * TextData;

	UFUNCTION(BlueprintCallable, Category = "GenerateCustomMesh")
		virtual	void initCreation(FVector MeshProperties);

	UFUNCTION(BlueprintCallable, Category = "GenerateCustomMesh")
		virtual	void CreateMeshCustomZ(FVector MeshProperties);

	UFUNCTION(BlueprintCallable, Category = "GenerateData")
		void GenerateTestMesh();
	
};
