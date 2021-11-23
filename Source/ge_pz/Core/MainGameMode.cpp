// Copyright Epic Games, Inc. All Rights Reserved.

#include "MainGameMode.h"
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
	
	PlayerControllerClass = AMainPlayerController::StaticClass();
}

