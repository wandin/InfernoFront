// Copyright Epidemic Studios

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "IF_UserWidget.generated.h"

/**
 * 
 */
UCLASS()
class INFERNOFRONT_API UIF_UserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);
	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;

protected:

	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
};
