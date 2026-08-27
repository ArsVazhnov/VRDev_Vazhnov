#include "InteractiveActor.h"

AInteractiveActor::AInteractiveActor()
{
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> MaterialAsset(TEXT("/Script/Engine.Material'/Game/Materials/M_HoveredObjectOverlay.M_HoveredObjectOverlay'"));
	HoveredOverlayMaterial = MaterialAsset.Object;
	
	UStaticMeshComponent* MeshComp = GetStaticMeshComponent();
	MeshComp->Mobility = EComponentMobility::Movable;
	MeshComp->SetSimulatePhysics(true);
	MeshComp->SetCollisionProfileName(TEXT("PhysicsActor"));
}

void AInteractiveActor::SetState(const EInteractiveActorState NewState)
{
	Data.State = NewState;
	UStaticMeshComponent* MeshComp = GetStaticMeshComponent();
	MeshComp->SetSimulatePhysics(NewState != EInteractiveActorState::Held);
	MeshComp->SetCollisionProfileName(NewState == EInteractiveActorState::Held ? "NoCollision" : "PhysicsActor");
	MeshComp->SetOverlayMaterial(NewState == EInteractiveActorState::Hovered ? HoveredOverlayMaterial : nullptr);
}