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
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	/* end Enemy interface */


protected:
	virtual void BeginPlay() override;
};
