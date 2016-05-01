// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class WizardsEditorTarget : TargetRules
{
	public WizardsEditorTarget(TargetInfo Target)
	{
		Type = TargetType.Editor;
        bUsesSteam = true;

    }

    //
    // TargetRules interface.
    //

    public override void SetupBinaries(
		TargetInfo Target,
		ref List<UEBuildBinaryConfiguration> OutBuildBinaryConfigurations,
		ref List<string> OutExtraModuleNames
		)
	{
		OutExtraModuleNames.Add("Wizards");
	}
}
