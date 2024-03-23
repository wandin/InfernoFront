// Copyright Epidemic Studios


#include "PlayerController/IFPlayerController.h"

#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Interfaces/IFInterface_Enemy.h"
#include "NiagaraFunctionLibrary.h"


AIFPlayerController::AIFPlayerController()
{
	bReplicates = true;
	DefaultMouseCursor = EMouseCursor::Hand;
	CachedDestination = FVector::ZeroVector;
	FollowTime = 0.f;
}

void AIFPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	CursorTrace();
}

void AIFPlayerController::BeginPlay()
{
	Super::BeginPlay();

	check(IFInputContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if(Subsystem)
	{
		Subsystem->AddMappingContext(IFInputContext, 0);
	}

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void AIFPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	UEnhancedInputComponent* EIC = CastChecked<UEnhancedInputComponent>(InputComponent);
	/* Movement With WASD*/
	EIC->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AIFPlayerController::Move);
	
	/*	 Move character with Mouse click */
	EIC->BindAction(MoveOnMouseClick, ETriggerEvent::Triggered, this, &AIFPlayerController::OnSetDestinationTriggered);
	EIC->BindAction(MoveOnMouseClick, ETriggerEvent::Canceled, this, &AIFPlayerController::OnSetDestinationReleased);
	EIC->BindAction(MoveOnMouseClick, ETriggerEvent::Completed, this, &AIFPlayerController::OnSetDestinationReleased);
}

void AIFPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector SideDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if(APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(SideDirection, InputAxisVector.X);
	}
}

void AIFPlayerController::CursorTrace()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	if(!CursorHit.bBlockingHit) return;

	LastActor = ThisActor;
	ThisActor = Cast<IIFInterface_Enemy>(CursorHit.GetActor());

	/**
	* Line trace from cursor. There are several scenarios:
	*  A. LastActor is null && ThisActor is null
	*		- Do nothing
	*	B. LastActor is null && ThisActor is valid
	*		- Highlight ThisActor
	*	C. LastActor is valid && ThisActor is null
	*		- UnHighlight LastActor
	*	D. Both actors are valid, but LastActor != ThisActor
	*		- UnHighlight LastActor, and Highlight ThisActor
	*	E. Both actors are valid, and are the same actor
	*		- Do nothing
	*/

	// Handle highlighting/unhighlighting based on cursor trace results as described above
	if(LastActor == nullptr)
	{
		if(ThisActor != nullptr)
		{
			//Case B
			ThisActor->HighlightActor();
		}
		else
		{
			//Case A - both are null, do nothing
		}
	}
	else // check if LastActor is valid
	{
		if(ThisActor == nullptr)
		{
			//Case C
			LastActor->UnHighlightActor();
		}
		else // both actors are valid
		{
			if(LastActor != ThisActor)
			{
				// Case D
				LastActor->UnHighlightActor();
				ThisActor->HighlightActor();
			}
			else
			{
				// Case E - do nothing
			}
		}
	}
}

void AIFPlayerController::OnSetDestinationTriggered()
{
	// We look for the location in the world where the player has pressed the input
	FHitResult Hit;
	const bool bHitSuccessful = GetHitResultUnderCursor(ECC_Visibility, true, Hit);
	// If we hit a surface, cache the location
	if (bHitSuccessful)
	{
		CachedDestination = Hit.Location;
	}
	// Move towards mouse pointer or touch
	APawn* ControlledPawn = GetPawn();
	if (ControlledPawn != nullptr)
	{
		const FVector WorldDirection = (CachedDestination - ControlledPawn->GetActorLocation()).GetSafeNormal();
		ControlledPawn->AddMovementInput(WorldDirection, 1.0, false);
	}
}

void AIFPlayerController::OnSetDestinationReleased()
{
	// We move there and spawn some particles
	UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, CachedDestination);

	UNiagaraFunctionLibrary::SpawnSystemAtLocation(this, FXCursor, CachedDestination, FRotator::ZeroRotator,
	                                               FVector(1.f, 1.f, 1.f), true, true, ENCPoolMethod::None, true);
}