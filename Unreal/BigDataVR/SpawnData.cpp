// Fill out your copyright notice in the Description page of Project Settings.

#include "BigDataVR.h"
#include "Engine.h"
#include "Spawner.h"
#include "TestShape.h"
#include "SpawnData.h"



// Sets default values
ASpawnData::ASpawnData()
{


 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;



	USphereComponent* SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	RootComponent = SphereComponent;

	MeshProperties.X = 1.0f;
	MeshProperties.Y = 1.0f;
	MeshProperties.Z = 1.0f;

	static ConstructorHelpers::FObjectFinder<UDataTable>
		FBig_Data_Yelp_BP(TEXT("DataTable'/Game/yelp.yelp'"));
	DataLookupTable = FBig_Data_Yelp_BP.Object;

}


void ASpawnData::ReadCSV(float offset, FTransform transform)
{
	FRotator rotation = this->GetActorRotation();
	FTransform LocalTransform;
	
	LocalTransform = transform;
	FVector Position;
	Position = LocalTransform.GetLocation();
	FVector OriginalLocation = Position;
	FVector OriginalMeshProperties = MeshProperties;

	if (DataLookupTable)
	{
		static const FString ContextString(TEXT("GENERAL"));

		uint32 RecordCount = DataLookupTable->GetTableData().Num();

		for (uint32 i = 0; i < RecordCount; i++)
		{
			FString IndexString = FString::FromInt((int32)i);
			FName IndexName = FName(*IndexString);

			FBig_Data_Yelp* GOLookupRow = DataLookupTable->FindRow<FBig_Data_Yelp>(IndexName, ContextString);

			// skip bad rows
			if (!GOLookupRow)
				continue;

			// get the row data
			FString UserID = GOLookupRow->UserId;
			int32 Rat = GOLookupRow->Rating;
			FString dId = GOLookupRow->BusinessId;

			GEngine->AddOnScreenDebugMessage(GEngine->ScreenMessages.Num() + 1, 6.0f, FColor::Green, UserID);
			// build the cube

			//TestShape* Mesh = ATestShape
			UWorld* const World = GetWorld();
			if (World)
			{

				ATestShape* ts = World->SpawnActor<ATestShape>(ATestShape::StaticClass(), LocalTransform.GetLocation(), rotation);

				MeshProperties.Z *= Rat;
				ts->initCreation(MeshProperties);
				ts->TextData->SetText(FText::FromString(UserID));

				Position.X += offset;
				LocalTransform.SetLocation(Position);
				MeshProperties = OriginalMeshProperties;
			}
			
		}

	}
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

