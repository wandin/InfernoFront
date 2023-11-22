// Copyright Epidemic Studios


#include "PlayerStates/IFPlayerState.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystem/AttributeSets/IFAttributeSet.h"

AIFPlayerState::AIFPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UIFAttributeSet>("AttributeSet");
	
	NetUpdateFrequency = 100.f;
}

UAbilitySystemComponent* AIFPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
