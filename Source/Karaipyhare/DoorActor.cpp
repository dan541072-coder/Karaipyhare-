#include "DoorActor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "Curves/CurveFloat.h"
#include "GameFramework/Pawn.h"

ADoorActor::ADoorActor()
{
	PrimaryActorTick.bCanEverTick = false;

	OpenAngle = 100.f;
	OpenDuration = 0.75f;
	bIsOpen = false;
	bPlayerInRange = false;

	DoorRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DoorRoot"));
	RootComponent = DoorRoot;

	DoorFrameMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorFrameMesh"));
	DoorFrameMesh->SetupAttachment(DoorRoot);
	DoorFrameMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	DoorPivot = CreateDefaultSubobject<USceneComponent>(TEXT("DoorPivot"));
	DoorPivot->SetupAttachment(DoorRoot);

	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
	DoorMesh->SetupAttachment(DoorPivot);
	DoorMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	InteractionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("InteractionBox"));
	InteractionBox->SetupAttachment(DoorRoot);
	InteractionBox->SetBoxExtent(FVector(150.f, 150.f, 100.f));
	InteractionBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	InteractionBox->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	InteractionBox->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);

	DoorTimeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("DoorTimeline"));

	AutoReceiveInput = EAutoReceiveInput::Player0;
}

void ADoorActor::BeginPlay()
{
	Super::BeginPlay();

	InteractionBox->OnComponentBeginOverlap.AddDynamic(this, &ADoorActor::OnBoxBeginOverlap);
	InteractionBox->OnComponentEndOverlap.AddDynamic(this, &ADoorActor::OnBoxEndOverlap);

	if (DoorCurve)
	{
		DoorUpdateEvent.BindUFunction(this, FName("HandleTimelineUpdate"));
		DoorTimeline->AddInterpFloat(DoorCurve, DoorUpdateEvent);

		DoorFinishedEvent.BindUFunction(this, FName("HandleTimelineFinished"));
		DoorTimeline->SetTimelineFinishedFunc(DoorFinishedEvent);
	}

	DoorTimeline->SetTimelineLength(OpenDuration);
	DoorTimeline->SetLooping(false);
}

void ADoorActor::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (PlayerInputComponent)
	{
		PlayerInputComponent->BindAction("Interactuar", IE_Pressed, this, &ADoorActor::Interact);
	}
}

void ADoorActor::Interact()
{
	if (!bPlayerInRange || !DoorCurve)
	{
		return;
	}

	if (bIsOpen)
	{
		DoorTimeline->Reverse();
	}
	else
	{
		DoorTimeline->Play();
	}

	bIsOpen = !bIsOpen;
}

void ADoorActor::HandleTimelineUpdate(float Value)
{
	FRotator NewRotation = FRotator(0.f, Value * OpenAngle, 0.f);
	DoorPivot->SetRelativeRotation(NewRotation);
}

void ADoorActor::HandleTimelineFinished()
{
	if (bIsOpen)
	{
		OnDoorOpened();
	}
	else
	{
		OnDoorClosed();
	}
}

void ADoorActor::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != this && OtherActor->IsA(APawn::StaticClass()))
	{
		bPlayerInRange = true;
	}
}

void ADoorActor::OnBoxEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && OtherActor != this && OtherActor->IsA(APawn::StaticClass()))
	{
		bPlayerInRange = false;
	}
}
