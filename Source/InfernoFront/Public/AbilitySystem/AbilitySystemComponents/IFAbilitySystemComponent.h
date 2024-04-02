// Copyright Epidemic Studios

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "IFAbilitySystemComponent.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FEffectAssetTags, const FGameplayTagContainer&); // To broadcast a container of Tags.

/**
 * 
 */
UCLASS()
class INFERNOFRONT_API UIFAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:

	void AbilityActorInfoSet();

	FEffectAssetTags EffectAssetTags;

protected:

	
	/**
	 * @brief  Delegate for when an effect is applied 
	 * @param AbilitySystemComponent 
	 * @param EffectSpec 
	 * @param ActiveEffectHandle 
	 */
	void EffectApplied(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle);
};
