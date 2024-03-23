// Copyright Epidemic Studios

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "IF_UserWidget.generated.h"

/**
 * @brief User widget class for handling UI elements in the game.
 */
UCLASS()
class INFERNOFRONT_API UIF_UserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	/** Function to set the widget controller */
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);

	/** Read-only property to store the widget controller */
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;

protected:
	/** Blueprint implementable event to notify when the widget controller is set */
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
};
