#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/TimelineComponent.h"
#include "Door.generated.h"

UENUM(BlueprintType)
enum class EDoorState : uint8
{
	Closed = 0 UMETA(DisplayName = "Closed"),
	Opening = 1 UMETA(DisplayName = "Opening"),
	Open = 2 UMETA(DisplayName = "Open"),
	Closing = 3 UMETA(DisplayName = "Closing")
};

UENUM(BlueprintType)
enum class EDoorType : uint8
{
	Rotating = 0 UMETA(DisplayName = "Rotating"),
	Sliding = 1 UMETA(DisplayName = "Sliding")
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorEvent);

UCLASS()
class KARAIPYHARE_API ADoor : public AActor
{
	GENERATED_BODY()

public:
	ADoor();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	// ==================== PROPIEDADES ====================

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Door|Component")
	class UStaticMeshComponent* DoorMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Door|Component")
	class UTimelineComponent* TimelineComponent;

	// Configuración
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door|Config")
	EDoorType DoorType = EDoorType::Rotating;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door|Config")
	FRotator DoorRotation = FRotator(0, 90, 0);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door|Config")
	FVector DoorOffset = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door|Config")
	float OpenDuration = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door|Config")
	float CloseDuration = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door|Config")
	bool bAutoClose = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door|Config")
	float AutoCloseDelay = 3.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door|Config")
	class UCurveFloat* EasingCurve;

	// Estado
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Door|State")
	EDoorState CurrentState = EDoorState::Closed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Door|State")
	bool bIsOpen = false;

	// ==================== EVENTOS ====================

	UPROPERTY(BlueprintAssignable, Category = "Door|Events")
	FDoorEvent OnDoorOpened;

	UPROPERTY(BlueprintAssignable, Category = "Door|Events")
	FDoorEvent OnDoorClosed;

	UPROPERTY(BlueprintAssignable, Category = "Door|Events")
	FDoorEvent OnDoorStartOpening;

	UPROPERTY(BlueprintAssignable, Category = "Door|Events")
	FDoorEvent OnDoorStartClosing;

	// ==================== FUNCIONES PÚBLICAS ====================

	UFUNCTION(BlueprintCallable, Category = "Door")
	void OpenDoor();

	UFUNCTION(BlueprintCallable, Category = "Door")
	void CloseDoor();

	UFUNCTION(BlueprintCallable, Category = "Door")
	void ToggleDoor();

	UFUNCTION(BlueprintCallable, Category = "Door")
	void SetDoorState(EDoorState NewState);

	UFUNCTION(BlueprintPure, Category = "Door")
	bool IsFullyOpen() const { return CurrentState == EDoorState::Open; }

	UFUNCTION(BlueprintPure, Category = "Door")
	bool IsFullyClosed() const { return CurrentState == EDoorState::Closed; }

	UFUNCTION(BlueprintPure, Category = "Door")
	bool IsMoving() const { return CurrentState == EDoorState::Opening || CurrentState == EDoorState::Closing; }

private:

	// ==================== VARIABLES PRIVADAS ====================

	FVector InitialLocation;
	FRotator InitialRotation;
	FTimerHandle AutoCloseTimerHandle;

	// ==================== FUNCIONES PRIVADAS ====================

	void SetupTimeline();
	void OnTimelineUpdate(float Value);
	void OnTimelineFinished();
	void ClearAutoCloseTimer();
	void StartAutoCloseTimer();
};
