
#include "RotationPlatform001.h"

ARotationPlatform001::ARotationPlatform001()
{
	PrimaryActorTick.bCanEverTick = true;
	RotationSpeed = 60.0f;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);


	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/SM_AssetPlatform.SM_AssetPlatform"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Materials/M_Rock_Basalt.M_Rock_Basalt"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}
}

void ARotationPlatform001::BeginPlay()
{
	Super::BeginPlay();
	SetActorLocation(FVector(440.0f, -600.0f, 180.0f));
	//SetActorRelativeLocation(FVector(-130.0f, 0.0f, 180.0f));
	
	
}

void ARotationPlatform001::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!FMath::IsNearlyZero(RotationSpeed))
	{
		AddActorWorldRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
		
	}
}

