// Copyright Epidemic Studios


#include "AbilitySystem/AbilitySystemComponents/IFAbilitySystemComponent.h"

void UIFAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UIFAbilitySystemComponent::EffectApplied);
}

void UIFAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent,
                                              const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle)
{
	GEngine->AddOnScreenDebugMessage(1, 9.f, FColor::Red, FString("EFFECT APPLIED!"));
}