#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "InteractiveActor.generated.h"

UENUM(BlueprintType)
enum class EInteractiveActorState : uint8
{
	Hovered UMETA(DisplayName = "Hovered"),
	Held UMETA(DisplayName = "Held")
};

USTRUCT(BlueprintType)
struct FInteractiveActorData
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly) FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadOnly) FString Type;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (ClampMin = 0, UIMin = 0)) float Weight;
};

UCLASS()
class VRDEV_VAZHNOV_API AInteractiveActor : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:
	AInteractiveActor();
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly) FInteractiveActorData Data;
	
	UFUNCTION(BlueprintCallable) void SetIsHovered(bool bIsHovered) const;
	UFUNCTION(BlueprintCallable) void SetIsHeld(bool bIsHeld) const;
	
private:
	UPROPERTY() UMaterialInterface* HoveredOverlayMaterial;
};