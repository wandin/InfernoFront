// Copyright Epidemic Studios

#pragma once

#include "CoreMinimal.h"
#include "Character/IFCharacter_Base.h"
#include "Interfaces/IFInterface_Enemy.h"
#include "IFCharacter_Enemy.generated.h"

/**
 * 
 */
UCLASS()
class INFERNOFRONT_API AIFCharacter_Enemy : public AIFCharacter_Base, public IIFInterface_Enemy
{
	GENERATED_BODY()

public:

	AIFCharacter_Enemy();
	
	/* Enemy Interface */
	/**
	 * @brief Function to highlight the actor.
	 *        Highlights the enemy character for visual identification.
	 */
	virtual void HighlightActor() override;
	/**
	 * @brief Function to remove highlighting from the actor.
	 *        Removes the highlight effect from the enemy character.
	 */
	virtual void UnHighlightActor() override;
	/* end Enemy interface */


protected:
	virtual void BeginPlay() override;

	virtual void InitAbilityActorInfo() override;
};
