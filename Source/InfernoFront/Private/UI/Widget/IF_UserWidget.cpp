// Copyright Epidemic Studios


#include "UI/Widget/IF_UserWidget.h"

void UIF_UserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;	// Set the widget controller to the provided controller object
	WidgetControllerSet();					// Trigger the WidgetControllerSet event
}
