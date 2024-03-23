// Copyright Epidemic Studios

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayEffectTypes.h"
#include "IF_EffectActor.generated.h"

class UAbilitySystemComponent;
class UGameplayEffect;


/**
 * @brief Enum defining the policy for applying effects.
 */
UENUM()
enum class EEffectApplicationPolicy
{
	ApplyOnOverlap,		// Apply the effect when overlapping with another actor
	ApplyOnEndOverlap,	// Apply the effect when ending overlap with another actor
	DoNotApply			// Do not apply the effect
};

/**
 * @brief Enum defining the policy for removing effects.
 */
UENUM()
enum class EEffectRemovalPolicy
{
	RemoveOnEndOverlap,	// Remove the effect when ending overlap with another actor
	DoNotRemove,		// Do not remove the effect
};

/**
 * @brief Actor class responsible for applying various types of gameplay effects to other actors.
 */
UCLASS()
class INFERNOFRONT_API AIF_EffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AIF_EffectActor();

protected:
	virtual void BeginPlay() override;

	/** Function called when this actor overlaps another actor */
	UFUNCTION(BlueprintCallable)
	void OnOverlap(AActor* TargetActor);

	/** Function called when this actor ends overlap with another actor */
	UFUNCTION(BlueprintCallable)
	void OnEndOverlap(AActor* TargetActor);

	/** Function to apply a gameplay effect to a target actor */
	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass);

	/** Flag indicating whether to destroy the actor on effect removal */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
	bool bDestroyOnEffectRemoval = false;
	
	/** Instant GameplayEffects and their application policy */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
	EEffectApplicationPolicy InstantApplicationPolicy = EEffectApplicationPolicy::DoNotApply;

	/** Duration GameplayEffect and its application policy */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category =  "Applied Effects")
	TSubclassOf<UGameplayEffect> DurationGameplayEffectClass;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
	EEffectApplicationPolicy DurationApplicationPolicy = EEffectApplicationPolicy::DoNotApply;

	/** Infinite GameplayEffects and their application policy */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category =  "Applied Effects")
	TSubclassOf<UGameplayEffect> InfiniteGameplayEffectClass;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
	EEffectApplicationPolicy InfiniteApplicationPolicy = EEffectApplicationPolicy::DoNotApply;

	/** Policy for removing infinite effects */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category =  "Applied Effects")
	EEffectRemovalPolicy InfiniteEffectRemovalPolicy = EEffectRemovalPolicy::RemoveOnEndOverlap;

	/** Map to store active effect handles */
	TMap<const FActiveGameplayEffectHandle, const UAbilitySystemComponent*> ActiveEffectHandles;

	/** Level of the actor */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category =  "Applied Effects")
	float ActorLevel = 1.0f;
};
