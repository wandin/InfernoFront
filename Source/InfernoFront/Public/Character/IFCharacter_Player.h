// Copyright Epidemic Studios

#pragma once

#include "CoreMinimal.h"
#include "Character/IFCharacter_Base.h"
#include "IFCharacter_Player.generated.h"

/**
 * @brief Player character class.
 * Represents a player character in the game.
 */
UCLASS()
class INFERNOFRONT_API AIFCharacter_Player : public AIFCharacter_Base
{
	GENERATED_BODY()

public:
	AIFCharacter_Player();

	/**
	 * @brief Called when this character is possessed by a controller.
	 * @param NewController  The controller possessing this character.
	 */
	virtual void PossessedBy(AController* NewController) override;
	/**
	 * @brief Called when the player state is replicated.
	 */
	virtual void OnRep_PlayerState() override;

private:

	void InitAbilityActorInfo();
	
};
