// Copyright Epidemic Studios

#pragma once

#include "CoreMinimal.h"
#include "Character/IFCharacter_Base.h"
#include "IFCharacter_Player.generated.h"

/**
 * 
 */
UCLASS()
class INFERNOFRONT_API AIFCharacter_Player : public AIFCharacter_Base
{
	GENERATED_BODY()

public:
	AIFCharacter_Player();

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

private:

	void InitAbilityActorInfo();
	
};
