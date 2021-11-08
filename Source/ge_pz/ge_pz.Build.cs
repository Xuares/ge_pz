// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ge_pz : ModuleRules
{
	public ge_pz(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
