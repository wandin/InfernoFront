// Copyright Epidemic Studios

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/IF_WidgetController.h"
#include "OverlayWidgetController.generated.h"

// Forward declaration of structs and delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChangedSignature, float, NewHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxHealthChangedSignature, float, NewMaxHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnManaChangedSignature, float, NewMana);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxManaChangedSignature, float, NewMaxMana);

struct FOnAttributeChangeData;
/**
 * @brief Widget controller class responsible for managing attributes related to health and mana.
 */
UCLASS(BlueprintType, Blueprintable)
class INFERNOFRONT_API UOverlayWidgetController : public UIF_WidgetController
{
	GENERATED_BODY()

public:

	// Override the functions to broadcast initial values and bind callbacks to dependencies
	virtual void BroadcastInitialValues() override;
	virtual void BindCallbacksToDependencies() override;

	// Delegates for attribute change events
	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnHealthChangedSignature OnHealthChanged;
	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnMaxHealthChangedSignature OnMaxHealthChanged;
	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnManaChangedSignature OnManaChanged;
	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnMaxManaChangedSignature OnMaxManaChanged;

protected:
	// Callback functions for attribute changes
	void HealthChanged(const FOnAttributeChangeData& Data) const;
	void MaxHealthChanged(const FOnAttributeChangeData& Data) const;
	void ManaChanged(const FOnAttributeChangeData& Data) const;
	void MaxManaChanged(const FOnAttributeChangeData& Data) const;
};
