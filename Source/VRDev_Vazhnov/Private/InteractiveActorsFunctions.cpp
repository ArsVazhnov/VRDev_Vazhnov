#include "InteractiveActorsFunctions.h"

AInteractiveActor* UInteractiveActorsFunctions::SpawnInteractiveActor(UObject* WorldContextObject, const TSubclassOf<AInteractiveActor> NewActorClass, const FTransform SpawnTransform)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (!World)
	{
		UE_LOG(LogTemp, Error, TEXT("SpawnInteractiveActor: Failed to get World from Context Object"));
		return nullptr;
	}
	AInteractiveActor* NewActor = World->SpawnActor<AInteractiveActor>(NewActorClass, SpawnTransform);
	if (!NewActor)
	{
		UE_LOG(LogTemp, Error, TEXT("SpawnInteractiveActor: Failed to Spawn Actor"));
		return nullptr;
	}
	return NewActor;
}

void UInteractiveActorsFunctions::DestroyInteractiveActor(AInteractiveActor* TargetActor)
{
	if (IsValid(TargetActor))
	{
		TargetActor->Destroy();
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("DestroyInteractiveActor: Target Actor is null, pending kill or garbage"));
	}
}