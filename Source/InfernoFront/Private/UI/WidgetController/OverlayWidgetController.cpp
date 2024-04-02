// Copyright Epidemic Studios


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/AbilitySystemComponents/IFAbilitySystemComponent.h"
#include "AbilitySystem/AttributeSets/IFAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	
	const UIFAttributeSet* IFAttributeSet = CastChecked<UIFAttributeSet>(AttributeSet);

	OnHealthChanged.Broadcast(IFAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(IFAttributeSet->GetMaxHealth());
	OnManaChanged.Broadcast(IFAttributeSet->GetMana());
	OnMaxManaChanged.Broadcast(IFAttributeSet->GetMaxMana());
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UIFAttributeSet* IFAttributeSet = CastChecked<UIFAttributeSet>(AttributeSet);
	if(IFAttributeSet)
	{
		/* Health */
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(IFAttributeSet->GetHealthAttribute()).AddUObject(this, &UOverlayWidgetController::HealthChanged);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(IFAttributeSet->GetMaxHealthAttribute()).AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);
		/* Mana */
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(IFAttributeSet->GetManaAttribute()).AddUObject(this, &UOverlayWidgetController::ManaChanged);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(IFAttributeSet->GetMaxManaAttribute()).AddUObject(this, &UOverlayWidgetController::MaxManaChanged);

		Cast<UIFAbilitySystemComponent>(AbilitySystemComponent)->EffectAssetTags.AddLambda([](const FGameplayTagContainer& AssetTags)
		{
			for (const FGameplayTag& Tag: AssetTags)
			{
				const FString Msg = FString::Printf(TEXT("GE Tag: %s"), *Tag.ToString());
				GEngine->AddOnScreenDebugMessage(-1, 1.5f, FColor::Green, Msg);
			}
		});
	}
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	// Broadcast health attribute change event
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	// Broadcast max health attribute change event
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::ManaChanged(const FOnAttributeChangeData& Data) const
{
	// Broadcast mana attribute change event
	OnManaChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxManaChanged(const FOnAttributeChangeData& Data) const
{
	// Broadcast max mana attribute change event
	OnMaxManaChanged.Broadcast(Data.NewValue);
}
