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
 * @brief Player controller class responsible for handling player input and interaction.
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

	/** Set up input bindings */
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
	/** Input context for the player controller */
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> IFInputContext;

	/** Input action for movement */
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	/** Input action for moving character on mouse click */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputAction* MoveOnMouseClick;

	/** Function to handle character movement */
	void Move(const FInputActionValue& InputActionValue);

	/** Function to trace cursor and handle highlighting/unhighlighting of actors */
	void CursorTrace();

	/** Actors used for tracing cursor position */
	IIFInterface_Enemy* LastActor;
	IIFInterface_Enemy* ThisActor;

	/** Cached destination for character movement */
	FVector CachedDestination;

	/** Time for how long the mouse button has been pressed */
	float FollowTime;
};
