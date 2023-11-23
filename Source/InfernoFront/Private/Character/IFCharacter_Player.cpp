// Copyright Epidemic Studios


#include "Character/IFCharacter_Player.h"

#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PlayerStates/IFPlayerState.h"

AIFCharacter_Player::AIFCharacter_Player()
{

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
	
}

void AIFCharacter_Player::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// Init Ability actor info for Server
	InitAbilityActorInfo();
}

void AIFCharacter_Player::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	//Init ability actor info for client
	InitAbilityActorInfo();
}

void AIFCharacter_Player::InitAbilityActorInfo()
{
	AIFPlayerState* IfPlayerState = GetPlayerState<AIFPlayerState>();
	check(IfPlayerState);
	IfPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(IfPlayerState, this);
	AbilitySystemComponent = IfPlayerState->GetAbilitySystemComponent();
	AttributeSet = IfPlayerState->GetAttributeSet();
}
