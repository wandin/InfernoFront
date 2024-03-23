// Copyright Epidemic Studios

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IFInterface_Enemy.generated.h"

// This class does not need to be modified.
/**
 * @brief Interface for enemy actors.
 */
UINTERFACE(MinimalAPI)
class UIFInterface_Enemy : public UInterface
{
	GENERATED_BODY()
};

/**
 * @brief Interface functions for enemy actors.
 *        Classes implementing this interface must provide implementations for these functions.
 */
class INFERNOFRONT_API IIFInterface_Enemy
{
	GENERATED_BODY()

public:

	/** Function to highlight the actor. */
	virtual void HighlightActor() = 0;
	/** Function to remove highlighting from the actor. */
	virtual void UnHighlightActor() = 0;

};
