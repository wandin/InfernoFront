// Copyright Epidemic Studios


#include "PlayerStates/IFPlayerState.h"

#include "AbilitySystemComponent.h"

#include "AbilitySystem/AbilitySystemComponents/IFAbilitySystemComponent.h"
#include "AbilitySystem/AttributeSets/IFAttributeSet.h"

AIFPlayerState::AIFPlayerState()
{
	// Create and initialize the ability system component
	AbilitySystemComponent = CreateDefaultSubobject<UIFAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	// Create and initialize the attribute set
	AttributeSet = CreateDefaultSubobject<UIFAttributeSet>("AttributeSet");

	// Set the network update frequency
	NetUpdateFrequency = 100.f;
}

UAbilitySystemComponent* AIFPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
