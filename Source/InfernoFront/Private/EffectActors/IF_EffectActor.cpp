// Copyright Epidemic Studios


#include "EffectActors/IF_EffectActor.h"

#include "AbilitySystem/AttributeSets/IFAttributeSet.h"
#include "AbilitySystemBlueprintLibrary.h"

AIF_EffectActor::AIF_EffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SetRootComponent(CreateDefaultSubobject<USceneComponent>("SceneRoot"));
}

void AIF_EffectActor::BeginPlay()
{
	Super::BeginPlay();
}

void AIF_EffectActor::OnOverlap(AActor* TargetActor)
{
	// Apply effects based on the configured policies
	if(InstantApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap)
	{
		ApplyEffectToTarget(TargetActor, InstantGameplayEffectClass);
	}
	if(DurationApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap)
	{
		ApplyEffectToTarget(TargetActor, DurationGameplayEffectClass);
	}
	if (InfiniteApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap)
	{
		ApplyEffectToTarget(TargetActor, InfiniteGameplayEffectClass);
	}
}

void AIF_EffectActor::OnEndOverlap(AActor* TargetActor)
{
	// Apply effects based on the configured policies
	if(InstantApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap)
	{
		ApplyEffectToTarget(TargetActor, InstantGameplayEffectClass);
	}
	if(DurationApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap)
	{
		ApplyEffectToTarget(TargetActor, DurationGameplayEffectClass);
	}
	if (InfiniteApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap)
	{
		ApplyEffectToTarget(TargetActor, InfiniteGameplayEffectClass);
	}
	
	// Remove infinite effects if configured
	if(InfiniteEffectRemovalPolicy == EEffectRemovalPolicy::RemoveOnEndOverlap)
	{
		// Get the ability system component of the target actor
		UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
		if(!TargetASC)	return;

		// Iterate over active effect handles and remove them
		TArray<FActiveGameplayEffectHandle> HandlesToRemove;
		for (auto handlePair : ActiveEffectHandles)
		{
			if (TargetASC == handlePair.Value)
			{
				TargetASC->RemoveActiveGameplayEffect(handlePair.Key);
				HandlesToRemove.Add(handlePair.Key);
			}
		}
		for(auto& Handle : HandlesToRemove)
		{
			ActiveEffectHandles.FindAndRemoveChecked(Handle);
		}
	}
}

void AIF_EffectActor::ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass)
{
	// Get the ability system component of the target actor
	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
	if(TargetASC == nullptr) return;
	check(GameplayEffectClass);

	// Create effect context handle and add this actor as a source
	FGameplayEffectContextHandle EffectContextHandle = TargetASC->MakeEffectContext();
	EffectContextHandle.AddSourceObject(this);

	// Create outgoing effect spec and apply it to the target actor
	const FGameplayEffectSpecHandle EffectSpecHandle = TargetASC->MakeOutgoingSpec(GameplayEffectClass, ActorLevel, EffectContextHandle);
	const FActiveGameplayEffectHandle ActiveEffectHandle = TargetASC->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());

	// Add the active effect handle to the map if it's an infinite effect and removal policy is set to remove on end overlap
	const bool bisInfinite = EffectSpecHandle.Data.Get()->Def.Get()->DurationPolicy == EGameplayEffectDurationType::Infinite;
	if(bisInfinite && InfiniteEffectRemovalPolicy == EEffectRemovalPolicy::RemoveOnEndOverlap)
	{
		ActiveEffectHandles.Add(ActiveEffectHandle, TargetASC);
	}
}