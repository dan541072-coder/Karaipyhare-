#include "Door.h"
#include "Components/StaticMeshComponent.h"
#include "Components/TimelineComponent.h"
#include "Curves/CurveFloat.h"
#include "TimerManager.h"
#include "Engine/World.h"

ADoor::ADoor()
{
	PrimaryActorTick.bCanEverTick = false;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
	DoorMesh->SetupAttachment(RootComponent);

	TimelineComponent = CreateDefaultSubobject<UTimelineComponent>(TEXT("TimelineComponent"));
	TimelineComponent->SetupAttachment(RootComponent);
}

void ADoor::BeginPlay()
{
	Super::BeginPlay();

	InitialLocation = DoorMesh->GetRelativeLocation();
	InitialRotation = DoorMesh->GetRelativeRotation();

	SetupTimeline();
}

void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADoor::SetupTimeline()
{
	if (!EasingCurve)
	{
		// Crear curva por defecto si no existe
		static ConstructorHelpers::FObjectFinder<UCurveFloat> DefaultCurve(
			TEXT("CurveFloat'/Engine/Blueprints/Curves/DefaultCurve.DefaultCurve'")
		);
		EasingCurve = DefaultCurve.Object;
	}

	TimelineComponent->AddInterpFloat(EasingCurve, FOnTimelineFloat::CreateDynamic(this, &ADoor::OnTimelineUpdate));
	TimelineComponent->SetTimelineFinishedFunc(FSimpleDelegate::CreateDynamic(this, &ADoor::OnTimelineFinished));
	TimelineComponent->SetLooping(false);
}

void ADoor::OpenDoor()
{
	if (CurrentState == EDoorState::Open || CurrentState == EDoorState::Opening)
	{
		return;
	}

	CurrentState = EDoorState::Opening;
	bIsOpen = true;
	ClearAutoCloseTimer();

	OnDoorStartOpening.Broadcast();

	TimelineComponent->SetTimelineLength(OpenDuration);
	TimelineComponent->PlayFromStart();
}

void ADoor::CloseDoor()
{
	if (CurrentState == EDoorState::Closed || CurrentState == EDoorState::Closing)
	{
		return;
	}

	CurrentState = EDoorState::Closing;
	bIsOpen = false;
	ClearAutoCloseTimer();

	OnDoorStartClosing.Broadcast();

	TimelineComponent->SetTimelineLength(CloseDuration);
	TimelineComponent->PlayFromStart();
}

void ADoor::ToggleDoor()
{
	if (bIsOpen)
	{
		CloseDoor();
	}
	else
	{
		OpenDoor();
	}
}

void ADoor::SetDoorState(EDoorState NewState)
{
	switch (NewState)
	{
	case EDoorState::Closed:
		CloseDoor();
		break;
	case EDoorState::Open:
		OpenDoor();
		break;
	default:
		break;
	}
}

void ADoor::OnTimelineUpdate(float Value)
{
	if (!DoorMesh)
	{
		return;
	}

	if (DoorType == EDoorType::Rotating)
	{
		// Interpolación de rotación
		FRotator NewRotation = FMath::Lerp(InitialRotation, InitialRotation + DoorRotation, Value);
		DoorMesh->SetRelativeRotation(NewRotation);
	}
	else if (DoorType == EDoorType::Sliding)
	{
		// Interpolación de posición
		FVector NewLocation = FMath::Lerp(InitialLocation, InitialLocation + DoorOffset, Value);
		DoorMesh->SetRelativeLocation(NewLocation);
	}
}

void ADoor::OnTimelineFinished()
{
	if (CurrentState == EDoorState::Opening)
	{
		CurrentState = EDoorState::Open;
		OnDoorOpened.Broadcast();

		if (bAutoClose)
		{
			StartAutoCloseTimer();
		}
	}
	else if (CurrentState == EDoorState::Closing)
	{
		CurrentState = EDoorState::Closed;
		OnDoorClosed.Broadcast();
	}
}

void ADoor::ClearAutoCloseTimer()
{
	if (GetWorld())
	{
		GetWorld()->GetTimerManager().ClearTimer(AutoCloseTimerHandle);
	}
}

void ADoor::StartAutoCloseTimer()
{
	if (GetWorld())
	{
		GetWorld()->GetTimerManager().SetTimer(
			AutoCloseTimerHandle,
			this,
			&ADoor::CloseDoor,
			AutoCloseDelay,
			false
		);
	}
}
