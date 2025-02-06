
#include "MovingPlatform01.h"

AMovingPlatform01::AMovingPlatform01()
{
	PrimaryActorTick.bCanEverTick = true;
	//MoveSpeed = 30.0f;
	MaxRange = FVector(0.0f, 300.0f, 0.0f);

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/Floor_400x400.Floor_400x400"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Materials/M_Wood_Pine.M_Wood_Pine"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial	(0, MaterialAsset.Object);
	}

}

void AMovingPlatform01::BeginPlay()
{
	Super::BeginPlay();
	
	SetActorLocation(FVector(200.0f, -340.0f, 250.0f));	
	StartLocation = GetActorLocation();
}

void AMovingPlatform01::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	NewLocation.Y += DeltaHeight * MaxRange.Y;
	RunningTime += DeltaTime;
	SetActorLocation(NewLocation);


	/*if (!FMath::IsNearlyZero(MoveSpeed))
	{
		AddActorWorldOffset(FVector(0.0f, MoveSpeed * DeltaTime, 0.0f));
	}*/

}



