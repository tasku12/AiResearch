#include "PatrolNode.h"

// Sets default values
APatrolNode::APatrolNode()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	bReplicates = false;
	bIsEditorOnlyActor = true;

	m_NodeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("NodeMesh"));
	m_NodeMesh->AttachTo(GetRootComponent());
	ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMeshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
	m_NodeMesh->SetStaticMesh(SphereMeshAsset.Object);
}

// Called when the game starts or when spawned
void APatrolNode::BeginPlay()
{
	Super::BeginPlay();
	PrimaryActorTick.bCanEverTick = false;
	bReplicates = false;
	bIsEditorOnlyActor = true;
}

