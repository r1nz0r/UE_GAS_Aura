// Copyright VisionLooks


#include "Player/AuraPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Interaction/EnemyInterface.h"

AAuraPlayerController::AAuraPlayerController()
{
    bReplicates = true;
}

void AAuraPlayerController::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

    CursorTrace();
}

void AAuraPlayerController::BeginPlay()
{
    Super::BeginPlay();

    checkf(AuraInputMappingContext, TEXT("Aura IMC is not valid!"));
    UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(
        GetLocalPlayer());

    checkf(Subsystem, TEXT("Cant get acces to player input local subsystem!"));
    Subsystem->ClearAllMappings();
    Subsystem->AddMappingContext(AuraInputMappingContext, 0);

    bShowMouseCursor = true;
    DefaultMouseCursor = EMouseCursor::Default;

    FInputModeGameAndUI InputModeData;
    InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
    InputModeData.SetHideCursorDuringCapture(false);
    SetInputMode(InputModeData);
}

void AAuraPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
    EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move);
}

void AAuraPlayerController::Move(const FInputActionValue& InputActionValue)
{
    const FVector2D InputAxisVector = InputActionValue.Get<FVector2d>();
    const FRotator YawControlRotation{0, GetControlRotation().Yaw, 0};

    const FVector ForwardDirection = FRotationMatrix(YawControlRotation).GetUnitAxis(EAxis::X);
    const FVector RightDirection = FRotationMatrix(YawControlRotation).GetUnitAxis(EAxis::Y);

    if (APawn* ControlledPawn = GetPawn<APawn>())
    {
        ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
        ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
    }
}

void AAuraPlayerController::CursorTrace()
{
    FHitResult CursorHit;
    GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
    
    LastActor = ThisActor;
    ThisActor = CursorHit.bBlockingHit ? CursorHit.GetActor() : nullptr;

    if(LastActor != ThisActor)
    {
        if(LastActor) 
        {
            LastActor->UnHighlightActor();
        }
        if(ThisActor) 
        {
            ThisActor->HighlightActor();
        }
    }
}
