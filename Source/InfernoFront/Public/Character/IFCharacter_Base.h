// Copyright Epidemic Studios

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "IFCharacter_Base.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

UCLASS(Abstract)
class INFERNOFRONT_API AIFCharacter_Base : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AIFCharacter_Base();

	/*	G A S */
	/**
	 * @brief 
	 * @return AbilitySystemComponent
	 */
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() const { return AttributeSet; }
	
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;

	/* G A S */
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;

	// making a virtual function in base character to be called from our character class and other characters, as enemies
	virtual	void InitAbilityActorInfo();

};