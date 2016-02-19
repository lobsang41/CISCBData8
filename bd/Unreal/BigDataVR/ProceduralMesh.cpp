// Fill out your copyright notice in the Description page of Project Settings.

#include "BigDataVR.h"
#include "ProceduralMesh.h"


// Sets default values
AProceduralMesh::AProceduralMesh()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// create the mesh component
	UProceduralMeshComponent* mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("ProceduralMesh"));

	// find the material and assign to the mesh
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> Material(TEXT("Material'/Game/DataMaterial2.DataMaterial2'"));
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

	Vertices.Add(FVector(0, 0, 0));
	Vertices.Add(FVector(0, 50, 0));
	Vertices.Add(FVector(0, 0, 50));

	Vertices.Add(FVector(0, 0, 50));
	Vertices.Add(FVector(0, 50, 0));
	Vertices.Add(FVector(0, 50, 50));

	Vertices.Add(FVector(50, 50, 0));
	Vertices.Add(FVector(50, 0, 50));
	Vertices.Add(FVector(50, 50,50));

	Vertices.Add(FVector(50, 0, 50));
	Vertices.Add(FVector(50, 50, 0));
	Vertices.Add(FVector(50, 0, 0));

	Vertices.Add(FVector(50, 50, 0));
	Vertices.Add(FVector(0, 50, 0));
	Vertices.Add(FVector(50, 0, 0));

	Vertices.Add(FVector(50, 0, 0));
	Vertices.Add(FVector(0, 50, 0));
	Vertices.Add(FVector(0, 0, 0));

	Vertices.Add(FVector(50, 0, 50));
	Vertices.Add(FVector(0, 50, 50));
	Vertices.Add(FVector(50, 50, 50));
	
	

	Vertices.Add(FVector(0, 0, 50));
	Vertices.Add(FVector(0, 50, 50));
	Vertices.Add(FVector(50, 0, 50));
	



	Triangles.Add(0);
	Triangles.Add(1);
	Triangles.Add(2);
	Triangles.Add(3);
	Triangles.Add(4);
	Triangles.Add(5);
	Triangles.Add(6);
	Triangles.Add(7);
	Triangles.Add(8);
	Triangles.Add(9);
	Triangles.Add(10);
	Triangles.Add(11);
	Triangles.Add(12);
	Triangles.Add(13);
	Triangles.Add(14);
	Triangles.Add(15);
	Triangles.Add(16);
	Triangles.Add(17);
	Triangles.Add(18);
	Triangles.Add(19);
	Triangles.Add(20);
	Triangles.Add(21);

	Triangles.Add(22);
	Triangles.Add(23);
	Triangles.Add(24);

	UV0.Add(FVector2D(0, 0));
	UV0.Add(FVector2D(0, 10));
	UV0.Add(FVector2D(10, 10));

	VertexColors.Add(FColor(10, 75, 100, 50));
	VertexColors.Add(FColor(20, 20, 60, 20));
	VertexColors.Add(FColor(20, 30, 100, 100));



	// create the mesh section, 0 for the first section, false at the end to stop collision being added
	mesh->CreateMeshSection(0, Vertices, Triangles, Normals, UV0, VertexColors, Tangents, false);
}

// Called when the game starts or when spawned
void AProceduralMesh::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProceduralMesh::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

