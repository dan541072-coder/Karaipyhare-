#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/TimelineComponent.h"
#include "DoorActor.generated.h"

class UBoxComponent;
class UStaticMeshComponent;
class UCurveFloat;
class UInputComponent;

UCLASS(Blueprintable, BlueprintType)
class KARAIPYHARE_API ADoorActor : public AActor
{
	GENERATED_BODY()

public:
	ADoorActor();

protected:
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Door")
	USceneComponent* DoorRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Door")
	UStaticMeshComponent* DoorFrameMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Door")
	USceneComponent* DoorPivot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Door")
	UStaticMeshComponent* DoorMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Door")
	UBoxComponent* InteractionBox;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Door")
	UTimelineComponent* DoorTimeline;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door")
	UCurveFloat* DoorCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door")
	float OpenAngle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door")
	float OpenDuration;

	UPROPERTY(BlueprintReadOnly, Category = "Door")
	bool bIsOpen;

	UPROPERTY(BlueprintReadOnly, Category = "Door")
	bool bPlayerInRange;

	UFUNCTION(BlueprintCallable, Category = "Door")
	void Interact();

	UFUNCTION(BlueprintImplementableEvent, Category = "Door")
	void OnDoorOpened();

	UFUNCTION(BlueprintImplementableEvent, Category = "Door")
	void OnDoorClosed();

protected:
	UFUNCTION()
	void HandleTimelineUpdate(float Value);

	UFUNCTION()
	void HandleTimelineFinished();

	UFUNCTION()
	void OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnBoxEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	FOnTimelineFloat DoorUpdateEvent;
	FOnTimelineEvent DoorFinishedEvent;
};
