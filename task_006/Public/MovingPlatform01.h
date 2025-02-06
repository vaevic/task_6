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

	FVector StartLocation; // ó�� ��ǥ���� �����ϴ� ����
	//FVector CurrentLocation; //���� ��ǥ���� �����ϴ� ����
	//FVector MoveRange; //������ ������ �����ϴ� �Լ� (����-ó��)

	UPROPERTY(EditAnywhere, BlueprintReadwrite, Category = "Platform|Properties")
	FVector MaxRange;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
