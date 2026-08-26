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

void AInteractiveActor::SetIsHovered(const bool bIsHovered) const
{
	UStaticMeshComponent* MeshComp = GetStaticMeshComponent();
	MeshComp->SetOverlayMaterial(bIsHovered && HoveredOverlayMaterial ? HoveredOverlayMaterial : nullptr);
}

void AInteractiveActor::SetIsHeld(const bool bIsHeld) const
{
	UStaticMeshComponent* MeshComp = GetStaticMeshComponent();
	MeshComp->SetSimulatePhysics(!bIsHeld);
	MeshComp->SetCollisionProfileName(bIsHeld ? TEXT("NoCollision") : TEXT("PhysicsActor"));
}