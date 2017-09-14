// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "TryBetterAgainGameMode.h"
#include "TryBetterAgainPlayerController.h"
#include "TryBetterAgainCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATryBetterAgainGameMode::ATryBetterAgainGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ATryBetterAgainPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}