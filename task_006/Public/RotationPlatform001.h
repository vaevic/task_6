#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotationPlatform001.generated.h"

UCLASS(Blueprintable, BlueprintType)
class TASK_006_API ARotationPlatform001 : public AActor
{
	GENERATED_BODY()
	
public:	
	ARotationPlatform001();

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadonly, Category = "Platform|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadwrite, Category = "Platform|Components")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform|Properties")
	float RotationSpeed;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
