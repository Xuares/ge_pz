// Copyright Epic Games, Inc. All Rights Reserved.

#include "MainGameMode.h"
#include "ge_pzCharacter.h"
#include "MainPlayerController.h"
#include "UObject/ConstructorHelpers.h"

AMainGameMode::AMainGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	static ConstructorHelpers::FClassFinder<AMainPlayerController> PlayerControllerBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/BP_PlayerControllerMain"));
	if (PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
	else
	{
		PlayerControllerClass = AMainPlayerController::StaticClass();
	}
}

