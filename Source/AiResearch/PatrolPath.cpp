#include "PatrolPath.h"
#include "PatrolNode.h"

#include "Components/SplineComponent.h"

// Sets default values
APatrolPath::APatrolPath()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	bReplicates = false;

	m_PatrolPath = CreateDefaultSubobject<USplineComponent>(TEXT("PatrolPathSpline"));
	m_PatrolPath->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void APatrolPath::BeginPlay()
{
	Super::BeginPlay();
	PrimaryActorTick.bCanEverTick = false;
	bReplicates = false;

	UpdateWaypoints();
}

void APatrolPath::UpdateWaypoints()
{
	// Update path position data
	m_Waypoints.Empty(m_PatrolPath->GetNumberOfSplinePoints());

	for (int i = 0; i < m_PatrolPath->GetNumberOfSplinePoints(); ++i)
	{
		m_Waypoints.Add(m_PatrolPath->GetLocationAtSplinePoint(i, ESplineCoordinateSpace::World));
	}
}

