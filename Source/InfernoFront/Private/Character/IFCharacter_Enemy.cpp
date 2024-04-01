// Copyright Epidemic Studios


#include "Character/IFCharacter_Enemy.h"

#include "AbilitySystem/AbilitySystemComponents/IFAbilitySystemComponent.h"
#include "AbilitySystem/AttributeSets/IFAttributeSet.h"
#include "InfernoFront/InfernoFront.h"

#include "PlayerStates/IFPlayerState.h"

AIFCharacter_Enemy::AIFCharacter_Enemy()
{
	// Set mesh collision response
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
	// Initialize Ability System Component
	AbilitySystemComponent = CreateDefaultSubobject<UIFAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	// Initialize Attribute Set
	AttributeSet = CreateDefaultSubobject<UIFAttributeSet>("AttributeSet");	
}

void AIFCharacter_Enemy::HighlightActor()
{
	// Set mesh custom depth to highlight
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	// Check if there is a weapon and highlight it
	if(Weapon)
	{
	Weapon->SetRenderCustomDepth(true);
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	}
}

void AIFCharacter_Enemy::UnHighlightActor()
{
	// Disable mesh custom depth
	GetMesh()->SetRenderCustomDepth(false);
	// Disable weapon custom depth if exists
	if(Weapon)
	{
		Weapon->SetRenderCustomDepth(false);
	}
}

void AIFCharacter_Enemy::BeginPlay()
{
	Super::BeginPlay();
	InitAbilityActorInfo();
}

void AIFCharacter_Enemy::InitAbilityActorInfo()
{
	// Initialize Ability Actor Info
	AbilitySystemComponent->InitAbilityActorInfo(this, this);

	// setAbilityActorInfo in AbilitySystemComponent, used to bind to delegates for now. 
	Cast<UIFAbilitySystemComponent>(AbilitySystemComponent)->AbilityActorInfoSet();

}
