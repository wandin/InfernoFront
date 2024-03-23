// Copyright Epidemic Studios

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "IFPlayerState.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

/**
 * @brief Player state class representing the state of a player in the game.
 */
UCLASS()
class INFERNOFRONT_API AIFPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AIFPlayerState();

	/* G A S */
	/** Function to get the ability system component */
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	/** Function to get the attribute set */
	UAttributeSet* GetAttributeSet() const { return AttributeSet; }

protected:

	/* G A S */
	/** Ability system component */
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	/** Attribute set */
	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
};
