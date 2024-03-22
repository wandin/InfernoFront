// Copyright Epidemic Studios


#include "Character/IFCharacter_Enemy.h"

#include "AbilitySystem/AbilitySystemComponents/IFAbilitySystemComponent.h"
#include "AbilitySystem/AttributeSets/IFAttributeSet.h"

#include "Components/PostProcessComponent.h"


#include "InfernoFront/InfernoFront.h"

AIFCharacter_Enemy::AIFCharacter_Enemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
	
	AbilitySystemComponent = CreateDefaultSubobject<UIFAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UIFAttributeSet>("AttributeSet");	
}

void AIFCharacter_Enemy::HighlightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	if(Weapon)
	{
	Weapon->SetRenderCustomDepth(true);
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	}
}

void AIFCharacter_Enemy::UnHighlightActor()
{
	GetMesh()->SetRenderCustomDepth(false);

	if(Weapon)
	{
		Weapon->SetRenderCustomDepth(false);
	}
}

void AIFCharacter_Enemy::BeginPlay()
{
	Super::BeginPlay();

	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}
