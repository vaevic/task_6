#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform01.generated.h"

UCLASS(Blueprintable,BlueprintType)
class TASK_006_API AMovingPlatform01 : public AActor
{
	GENERATED_BODY()
	
public:	
	AMovingPlatform01();

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Platform|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadwrite, Category = "Platform|Components")
	UStaticMeshComponent* StaticMeshComp;

	/*UPROPERTY(EditAnywhere, BlueprintReadwirte, Category = "Platform|Properties")
	float MoveSpeed;*/
	float RunningTime;

	FVector StartLocation; // 처음 좌표값을 저장하는 변수
	//FVector CurrentLocation; //현재 좌표값을 저장하는 변수
	//FVector MoveRange; //움직인 범위를 도출하는 함수 (현재-처음)

	UPROPERTY(EditAnywhere, BlueprintReadwrite, Category = "Platform|Properties")
	FVector MaxRange;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
