#pragma once

#include "CoreMinimal.h"
#include "InteractiveActor.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "InteractiveActorsFunctions.generated.h"

UCLASS()
class VRDEV_VAZHNOV_API UInteractiveActorsFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject")) static AInteractiveActor* SpawnInteractiveActor(UObject* WorldContextObject, TSubclassOf<AInteractiveActor> NewActorClass, FTransform SpawnTransform);
	UFUNCTION(BlueprintCallable) static void DestroyInteractiveActor(AInteractiveActor* TargetActor);
};