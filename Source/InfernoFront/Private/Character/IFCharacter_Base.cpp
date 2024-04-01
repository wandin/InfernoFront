// Copyright Epidemic Studios


#include "Character/IFCharacter_Base.h"

// Sets default values
AIFCharacter_Base::AIFCharacter_Base()
{
	PrimaryActorTick.bCanEverTick = false;


	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

UAbilitySystemComponent* AIFCharacter_Base::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AIFCharacter_Base::BeginPlay()
{
	Super::BeginPlay();
	
}

void AIFCharacter_Base::InitAbilityActorInfo()
{
	
}
