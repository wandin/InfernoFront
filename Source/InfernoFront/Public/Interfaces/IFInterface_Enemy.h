// Copyright Epidemic Studios

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IFInterface_Enemy.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIFInterface_Enemy : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class INFERNOFRONT_API IIFInterface_Enemy
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:


	virtual void HighlightActor() = 0;
	virtual void UnHighlightActor() = 0;

};
