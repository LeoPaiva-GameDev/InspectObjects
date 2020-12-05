// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Pickup : ModuleRules
{
	public Pickup(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
