// Copyright Epidemic Studios


#include "UI/WidgetController/IF_WidgetController.h"

void UIF_WidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.AttributeSet;
}

void UIF_WidgetController::BroadcastInitialValues()
{
	
}

void UIF_WidgetController::BindCallbacksToDependencies()
{
	
}
