// Copyright Epidemic Studios


#include "UI/Widget/IF_UserWidget.h"

void UIF_UserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
