// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PatrolPath.generated.h"

class USplineComponent;

UCLASS()
class AIRESEARCH_API APatrolPath : public AActor
{
	GENERATED_BODY()
	
public:	

	// Sets default values for this actor's properties
	APatrolPath();

	UPROPERTY(EditAnywhere)
	USplineComponent* m_PatrolPath;

	UPROPERTY(BlueprintReadOnly)
	TArray<FVector> m_Waypoints;

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void UpdateWaypoints();
};
