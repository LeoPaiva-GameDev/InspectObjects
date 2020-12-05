// Copyright Epic Games, Inc. All Rights Reserved.

#include "PickupGameMode.h"
#include "PickupHUD.h"
#include "PickupCharacter.h"
#include "UObject/ConstructorHelpers.h"

APickupGameMode::APickupGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = APickupHUD::StaticClass();
}
