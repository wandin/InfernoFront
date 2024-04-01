// Copyright Epidemic Studios


#include "Character/IFCharacter_Player.h"

#include "AbilitySystemComponent.h"

#include "AbilitySystem/AbilitySystemComponents/IFAbilitySystemComponent.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "PlayerController/IFPlayerController.h"
#include "PlayerStates/IFPlayerState.h"
#include "UI/IF_HUD.h"

AIFCharacter_Player::AIFCharacter_Player()
{
	// Configure character movement settings
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;
	// Disable controller rotation
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
	// Retrieve the player state
	AIFPlayerState* IfPlayerState = GetPlayerState<AIFPlayerState>();
	check(IfPlayerState);
	
	// Initialize ability actor info using the player state's ability system component
	IfPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(IfPlayerState, this);
	
	Cast<UIFAbilitySystemComponent>(IfPlayerState->GetAbilitySystemComponent())->AbilityActorInfoSet();
	
	AbilitySystemComponent = IfPlayerState->GetAbilitySystemComponent();
	AttributeSet = IfPlayerState->GetAttributeSet();

	// Initialize the overlay HUD for the player controller
	if(AIFPlayerController* IFPlayerController = Cast<AIFPlayerController>(GetController()))
	{
		if(AIF_HUD* HUD = Cast<AIF_HUD>(IFPlayerController->GetHUD()))
		{
			HUD->InitOverlay(IFPlayerController, IfPlayerState, AbilitySystemComponent, AttributeSet);
		}
	}
}
