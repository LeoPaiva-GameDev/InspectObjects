// Code by Leonardo Paiva

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Camera/CameraComponent.h"
#include "PickupActor.generated.h"

UCLASS()
class PICKUP_API APickupActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickupActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	//Actor Components
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MeshComponent;
	
	UPROPERTY(EditAnywhere)
	USceneComponent* HoldingComponent;
	
	//Functions
	UFUNCTION()
    void Pickup();
	
	UFUNCTION()
	void RotateActor();
	
	//Variables
	bool bIsHolding;
	bool bIsGravityEnabled;
	
	FRotator ControlRotation;
	ACharacter* MainCharacter;
	UCameraComponent* PlayerCamera;
	FVector ForwardVector;

	UPROPERTY(EditAnywhere)
	float ThrowForce;
};
