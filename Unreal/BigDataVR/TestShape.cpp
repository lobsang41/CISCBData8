// Fill out your copyright notice in the Description page of Project Settings.

#include "BigDataVR.h"
#include "TestShape.h"


// Sets default values
ATestShape::ATestShape()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("ProceduralMesh"));

	/*
	// create the mesh component
	UProceduralMeshComponent* mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("ProceduralMesh"));
	*/
	// find the material and assign to the mesh
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> Material(TEXT("Material'/Game/BaseMaterial.BaseMaterial'"));
	mesh->SetMaterial(0, Material.Object);

	// set the mesh as the root component
	RootComponent = mesh;
	/*
	// define the arrays
	TArray<FVector> Vertices;
	TArray<int32> Triangles;
	TArray<FVector> Normals;
	TArray<FVector2D> UV0;
	TArray<FColor> VertexColors;
	TArray<FProcMeshTangent> Tangents;

	// fill all the arrays 

	Vertices.Add(FVector(0, -25, 0));
	Vertices.Add(FVector(25, 50, 0));
	Vertices.Add(FVector(25, 0, 50));

	Vertices.Add(FVector(25, 50, 0));
	Vertices.Add(FVector(50, -25, 0));
	Vertices.Add(FVector(25, 0, 50));

	Vertices.Add(FVector(0, -25, 0));
	Vertices.Add(FVector(25, 0, 50));
	Vertices.Add(FVector(50, -25, 0));



	Triangles.Add(0);
	Triangles.Add(1);
	Triangles.Add(2);
	Triangles.Add(3);
	Triangles.Add(4);
	Triangles.Add(5);
	Triangles.Add(6);
	Triangles.Add(7);
	Triangles.Add(8);


	UV0.Add(FVector2D(0, 0));
	UV0.Add(FVector2D(0, 10));
	UV0.Add(FVector2D(10, 10));
	UV0.Add(FVector2D(0, 0));
	UV0.Add(FVector2D(0, 10));
	UV0.Add(FVector2D(10, 10));
	UV0.Add(FVector2D(0, 0));
	UV0.Add(FVector2D(0, 10));
	UV0.Add(FVector2D(10, 10));




	VertexColors.Add(FColor(100, 100, 100, 100));
	VertexColors.Add(FColor(100, 100, 100, 100));
	VertexColors.Add(FColor(20, 30, 100, 100));
	VertexColors.Add(FColor(10, 75, 100, 50));
	VertexColors.Add(FColor(20, 20, 60, 20));
	VertexColors.Add(FColor(20, 30, 100, 100));
	VertexColors.Add(FColor(10, 75, 100, 50));
	VertexColors.Add(FColor(20, 20, 60, 20));
	VertexColors.Add(FColor(20, 30, 100, 100));




	// create the mesh section, 0 for the first section, false at the end to stop collision being added
	mesh->CreateMeshSection(0, Vertices, Triangles, Normals, UV0, VertexColors, Tangents, false);

	*/
	
}


void ATestShape::initCreation(FVector MeshProperties)
{/*
	// create the mesh component
	//mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("ProceduralMesh"));

	// find the material and assign to the mesh
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> Material(TEXT("Material'/Game/BaseMaterial.BaseMaterial'"));
	mesh->SetMaterial(0, Material.Object);

	// set the mesh as the root component
	RootComponent = mesh;
	*/
	// define the arrays
	TArray<FVector> Vertices;
	TArray<int32> Triangles;
	TArray<FVector> Normals;
	TArray<FVector2D> UV0;
	TArray<FColor> VertexColors;
	TArray<FProcMeshTangent> Tangents;

	// fill all the arrays 

	Vertices.Add(FVector(0, -25, 0));
	Vertices.Add(FVector(25, 50 * MeshProperties.X, 0));
	Vertices.Add(FVector(25, 0, 50 * MeshProperties.Z));

	Vertices.Add(FVector(25, 50 * MeshProperties.X, 0));
	Vertices.Add(FVector(50 * MeshProperties.Y, -25 , 0));
	Vertices.Add(FVector(25, 0, 50 * MeshProperties.Z));

	Vertices.Add(FVector(0, -25, 0));
	Vertices.Add(FVector(25, 0, 50 * MeshProperties.Z));
	Vertices.Add(FVector(50 * MeshProperties.Y, -25, 0));



	Triangles.Add(0);
	Triangles.Add(1);
	Triangles.Add(2);
	Triangles.Add(3);
	Triangles.Add(4);
	Triangles.Add(5);
	Triangles.Add(6);
	Triangles.Add(7);
	Triangles.Add(8);


	UV0.Add(FVector2D(0, 0));
	UV0.Add(FVector2D(0, 10));
	UV0.Add(FVector2D(10, 10));
	UV0.Add(FVector2D(0, 0));
	UV0.Add(FVector2D(0, 10));
	UV0.Add(FVector2D(10, 10));
	UV0.Add(FVector2D(0, 0));
	UV0.Add(FVector2D(0, 10));
	UV0.Add(FVector2D(10, 10));




	VertexColors.Add(FColor(100, 100, 100, 100));
	VertexColors.Add(FColor(100, 100, 100, 100));
	VertexColors.Add(FColor(20, 30, 100, 100));
	VertexColors.Add(FColor(10, 75, 100, 50));
	VertexColors.Add(FColor(20, 20, 60, 20));
	VertexColors.Add(FColor(20, 30, 100, 100));
	VertexColors.Add(FColor(10, 75, 100, 50));
	VertexColors.Add(FColor(20, 20, 60, 20));
	VertexColors.Add(FColor(20, 30, 100, 100));




	// create the mesh section, 0 for the first section, false at the end to stop collision being added
	mesh->CreateMeshSection(0, Vertices, Triangles, Normals, UV0, VertexColors, Tangents, false);

}



// Called when the game starts or when spawned
void ATestShape::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestShape::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ATestShape::GenerateTestMesh()
{
	int xPos = 200;
	for (int i = 0; i < 2; i++)
	{
		
	
		// create the mesh component
		UProceduralMeshComponent* mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("ProceduralMesh"));
		
		// find the material and assign to the mesh
		static ConstructorHelpers::FObjectFinder<UMaterialInterface> Material(TEXT("Material'/Game/BaseMateriak.BaseMaterial'"));
		mesh->SetMaterial(0, Material.Object);
		
		// set the mesh as the root component
		RootComponent = mesh;
		
		// define the arrays
		TArray<FVector> Vertices;
		TArray<int32> Triangles;
		TArray<FVector> Normals;
		TArray<FVector2D> UV0;
		TArray<FColor> VertexColors;
		TArray<FProcMeshTangent> Tangents;

		// fill all the arrays 

		Vertices.Add(FVector(0, -25, 0));
		Vertices.Add(FVector(25, 50, 0));
		Vertices.Add(FVector(25, 0, 50));

		Vertices.Add(FVector(25, 50, 0));
		Vertices.Add(FVector(50, -25, 0));
		Vertices.Add(FVector(25, 0, 50));

		Vertices.Add(FVector(0, -25, 0));
		Vertices.Add(FVector(25, 0, 50));
		Vertices.Add(FVector(50, -25, 0));



		Triangles.Add(0);
		Triangles.Add(1);
		Triangles.Add(2);
		Triangles.Add(3);
		Triangles.Add(4);
		Triangles.Add(5);
		Triangles.Add(6);
		Triangles.Add(7);
		Triangles.Add(8);


		UV0.Add(FVector2D(0, 0));
		UV0.Add(FVector2D(0, 10));
		UV0.Add(FVector2D(10, 10));

		VertexColors.Add(FColor(10, 75, 100, 50));
		VertexColors.Add(FColor(20, 20, 60, 20));
		VertexColors.Add(FColor(20, 30, 100, 100));



		// create the mesh section, 0 for the first section, false at the end to stop collision being added
		mesh->CreateMeshSection(0, Vertices, Triangles, Normals, UV0, VertexColors, Tangents, false);
		FVector MeshLocation = mesh->GetComponentTransform().GetLocation();
		MeshLocation.Y += xPos;
	}
}

