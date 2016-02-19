// Fill out your copyright notice in the Description page of Project Settings.

#include "BigDataVR.h"
#include "Spawner.h"
#include "Engine.h"
#include "TestShape.h"
#include "Engine/DataTable.h"



/** Yelp Base data */

USTRUCT(blueprintType)
struct FGameObjectTable : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

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




// Sets default values
ASpawner::ASpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshProperties.X = 1.0f;
	MeshProperties.Y = 1.0f;
	MeshProperties.Z = 1.0f;
}

// Called when the game starts or when spawned
void ASpawner::BeginPlay()
{
	Super::BeginPlay();
	


	
}

// Called every frame
void ASpawner::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	
}

void ASpawner::GenerateObjects()
{
	int32 offset = 60;
	FVector location = this->GetActorLocation();
	
	FRotator rotation = this->GetActorRotation();

	//TestShape* Mesh = ATestShape
	UWorld* const World = GetWorld();
	if (World)
	{
		
		for (int i = 0; i < 3; i++ ) {
		
			ATestShape* ts = World->SpawnActor<ATestShape>(ATestShape::StaticClass(), location, rotation);
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Instanciando");
			location.X += offset;
		}
	}


}


void ASpawner::GenerateObjectsAmount(int32 HowMany,int32 BreakCount, float offset)
{
	
	int32 temp = 0;
	FVector location = this->GetActorLocation();
	FRotator rotation = this->GetActorRotation();
	FVector OriginalLocation = location;
	//TestShape* Mesh = ATestShape
	UWorld* const World = GetWorld();
	if (World)
	{

		for (int i = 0; i < HowMany; i++)
		{

				ATestShape* ts = World->SpawnActor<ATestShape>(ATestShape::StaticClass(), location, rotation);
				ts->initCreation(MeshProperties);
				location.X += offset;
				
				temp++;
				if (temp == BreakCount) {
					location.X = OriginalLocation.X;
					location.Y += offset;
					temp = 0;
				}

			
		}

	}
}

