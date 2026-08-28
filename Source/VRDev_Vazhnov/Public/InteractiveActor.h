#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "InteractiveActor.generated.h"

UENUM(BlueprintType)
enum class EInteractiveActorState : uint8
{
	Free UMETA(DisplayName = "Free"),
	Hovered UMETA(DisplayName = "Hovered"),
	Held UMETA(DisplayName = "Held")
};

USTRUCT(BlueprintType)
struct FInteractiveActorData
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadOnly) EInteractiveActorState State = EInteractiveActorState::Free;
	UPROPERTY(BlueprintReadOnly) FString Type;
	UPROPERTY(EditAnywhere, BlueprintReadOnly) FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadOnly) FString Description;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (ClampMin = 0.0f, UIMin = 0.0f)) float Weight = 0.0f;
};

UCLASS()
class VRDEV_VAZHNOV_API AInteractiveActor : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:
	AInteractiveActor();
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly) FInteractiveActorData Data;
	
	UFUNCTION(BlueprintCallable) void SetState(EInteractiveActorState NewState);
	
private:
	UPROPERTY() UMaterialInterface* HoveredOverlayMaterial;
};