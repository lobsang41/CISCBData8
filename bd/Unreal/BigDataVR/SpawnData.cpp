// Fill out your copyright notice in the Description page of Project Settings.

#include "BigDataVR.h"
#include "Engine.h"
#include "SpawnData.h"


// Sets default values
ASpawnData::ASpawnData()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	USphereComponent* SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	RootComponent = SphereComponent;


	UProceduralMeshComponent* mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("GeneratedMesh"));
	// setup sizes
	float cubeSize = 10.f;
	float cubeSpacing = 50.f;

	// find the material and add it to the mesh
	//static ConstructorHelpers::FObjectFinder<UMaterialInterface> Material(TEXT("Material'/Game/Materials/BaseMat.BaseMat'"));
	//mesh->SetMaterial(0, Material.Object);





	TArray<FVector> vertices;

	vertices.Add(FVector(0, -50, 0));
	vertices.Add(FVector(0, 50, 0));
	vertices.Add(FVector(0, 0, 50));

	TArray<int32> Triangles;
	Triangles.Add(0);
	Triangles.Add(1);
	Triangles.Add(2);

	// Obtenemos los datos de la tabla
	//UDataTable* DataLookupTable;
	//static ConstructorHelpers::FObjectFinder<UDataTable>Big_Data_BP(TEXT("DataTable'/Game/SampleData.SampleData'"));
	//DataLookupTable = Big_Data_BP.Object;
	for (int32 i = 1; i < 5; i++)
	{
		TArray<FVector> vertices2;

		vertices2.Add(FVector(0, -50 + cubeSpacing, 0));
		vertices2.Add(FVector(0, 50 + cubeSpacing, 0));
		vertices2.Add(FVector(0, 0, 50 + cubeSpacing));
	
		mesh->CreateMeshSection(i, vertices2, Triangles, TArray<FVector>(), TArray<FVector2D>(), TArray<FColor>(), TArray<FProcMeshTangent>(), false);
		cubeSpacing += 50.0f;
	}


	mesh->AttachTo(RootComponent);

}

// Called when the game starts or when spawned
void ASpawnData::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpawnData::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}


void ASpawnData::Generate(float x, float y)
{

	USphereComponent* SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	RootComponent = SphereComponent;


	UProceduralMeshComponent* mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("GeneratedMesh"));
	// setup sizes
	float cubeSize = 10.f;
	float cubeSpacing = 10.f;

	TArray<FVector> vertices;

	vertices.Add(FVector(0 + cubeSpacing, -50 + cubeSpacing, 0));
	vertices.Add(FVector(0, 50, 0));
	vertices.Add(FVector(0, 0, 50));

	TArray<int32> Triangles;
	Triangles.Add(0);
	Triangles.Add(1);
	Triangles.Add(2);


	mesh->CreateMeshSection(0, vertices, Triangles, TArray<FVector>(), TArray<FVector2D>(), TArray<FColor>(), TArray<FProcMeshTangent>(), false);
}

void ASpawnData::GenerateTestMesh(int32 times)
{
	for (int32 i = 0; i < times; i++)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Ejecutando loop"));
		Generate(2, 2);
	}
}

