// Copyright Epic Games, Inc. All Rights Reserved.

#include "ge_pzGameMode.h"
#include "ge_pzCharacter.h"
#include "UObject/ConstructorHelpers.h"

Age_pzGameMode::Age_pzGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
