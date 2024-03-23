// Copyright Epidemic Studios


#include "UI/WidgetController/IF_WidgetController.h"

void UIF_WidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	// Set the widget controller parameters
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.AttributeSet;
}

void UIF_WidgetController::BroadcastInitialValues()
{
	// Implement broadcasting initial values if needed
	// This function can be overridden in derived classes to perform specific initialization tasks
}

void UIF_WidgetController::BindCallbacksToDependencies()
{
	// Implement binding callbacks to dependencies if needed
	// This function can be overridden in derived classes to establish event bindings or listeners
}