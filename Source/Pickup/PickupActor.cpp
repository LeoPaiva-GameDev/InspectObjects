// Code by Leonardo Paiva


#include "PickupActor.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APickupActor::APickupActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetSimulatePhysics(true);
	RootComponent = MeshComponent;

	bIsHolding = false;
	bIsGravityEnabled = true;

	ThrowForce = 100000.f;
}

// Called when the game starts or when spawned
void APickupActor::BeginPlay()
{
	Super::BeginPlay();

	MainCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);
	PlayerCamera = MainCharacter->FindComponentByClass<UCameraComponent>();

	TArray<USceneComponent*> Components;

	MainCharacter->GetComponents(Components);

	if(Components.Num() > 0)
	{
		for(auto& Comp : Components)
		{
			if(Comp->GetName() == "HoldingComponent")
			{
				HoldingComponent = Cast<USceneComponent>(Comp);
			}
		}
	}
}

// Called every frame
void APickupActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(bIsHolding && HoldingComponent)
	{
		SetActorLocationAndRotation(HoldingComponent->GetComponentLocation(), HoldingComponent->GetComponentRotation());
		
	}
}

void APickupActor::Pickup()
{
	bIsHolding = !bIsHolding;
	bIsGravityEnabled = !bIsGravityEnabled;
	MeshComponent->SetEnableGravity(bIsGravityEnabled);
	MeshComponent->SetSimulatePhysics(bIsHolding ? false : true);
	MeshComponent->SetCollisionEnabled(bIsHolding ? ECollisionEnabled::NoCollision : ECollisionEnabled::QueryAndPhysics);

	if(!bIsHolding)
	{
		ForwardVector = PlayerCamera->GetForwardVector();
		MeshComponent->AddForce(ForwardVector * ThrowForce * MeshComponent->GetMass());
	}
}

void APickupActor::RotateActor()
{
	ControlRotation = GetWorld()->GetFirstPlayerController()->GetControlRotation();
	SetActorRotation(FQuat(ControlRotation));
}



