// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Wizards : ModuleRules
{

    public Wizards(TargetInfo Target)
	{
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "UMG", "OnlineSubsystem", "OnlineSubsystemUtils"});
        PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
        DynamicallyLoadedModuleNames.Add("OnlineSubsystemSteam");
    }
}
