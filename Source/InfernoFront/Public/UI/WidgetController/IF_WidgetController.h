// Copyright Epidemic Studios

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "IF_WidgetController.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;

// Struct to hold widget controller parameters
USTRUCT(BlueprintType)
struct FWidgetControllerParams
{
	GENERATED_BODY()

	FWidgetControllerParams() {}
	FWidgetControllerParams(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
		: PlayerController(PC), PlayerState(PS), AbilitySystemComponent(ASC), AttributeSet(AS) {}

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<APlayerController> PlayerController = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<APlayerState> PlayerState = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UAttributeSet> AttributeSet = nullptr;
};

/**
 * @brief Widget controller class responsible for managing parameters and dependencies related to a widget.
 */
UCLASS()
class INFERNOFRONT_API UIF_WidgetController : public UObject
{
	GENERATED_BODY()

public:
	// Function to set widget controller parameters
	UFUNCTION(BlueprintCallable)
	void SetWidgetControllerParams(const FWidgetControllerParams& WCParams);
	// Virtual function to broadcast initial values
	virtual void BroadcastInitialValues();
	// Virtual function to bind callbacks to dependencies
	virtual void BindCallbacksToDependencies();
protected:
	// Player controller
	UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
	TObjectPtr<APlayerController> PlayerController;
	// Player state
	UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
	TObjectPtr<APlayerState> PlayerState;
	// Ability system component
	UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	// Attribute set
	UPROPERTY(BlueprintReadOnly, Category="WidgetController")
	TObjectPtr<UAttributeSet> AttributeSet;
};