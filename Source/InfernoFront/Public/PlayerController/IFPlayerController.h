// Copyright Epidemic Studios

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "IFPlayerController.generated.h"


struct FInputActionValue;

class IIFInterface_Enemy;
class UInputAction;
class UInputMappingContext;
class UNiagaraSystem;

/**
 * 
 */
UCLASS()
class INFERNOFRONT_API AIFPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AIFPlayerController();
	virtual void PlayerTick(float DeltaTime) override;
protected:
	virtual void BeginPlay() override;
	
	virtual void SetupInputComponent() override;
	
	/** FX Class that we will spawn when clicking */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UNiagaraSystem* FXCursor;

	/** Time Threshold to know if it was a short press */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	float ShortPressThreshold;
	
	/** True if the controlled character should navigate to the mouse cursor. */
	uint32 bMoveToMouseCursor : 1;
	
	/** Input handlers for SetDestination action. */
	void OnSetDestinationTriggered();
	void OnSetDestinationReleased();
	
private:
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> IFInputContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputAction* MoveOnMouseClick;
	
	void Move(const FInputActionValue& InputActionValue);

	void CursorTrace();
	
	TObjectPtr<IIFInterface_Enemy> LastActor;
	TObjectPtr<IIFInterface_Enemy> ThisActor;

	FVector CachedDestination;

	float FollowTime; // For how long it has been pressed
};
