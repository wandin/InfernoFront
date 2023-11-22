// Copyright Epidemic Studios

using UnrealBuildTool;
using System.Collections.Generic;

public class InfernoFrontTarget : TargetRules
{
	public InfernoFrontTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V4;

		ExtraModuleNames.AddRange( new string[] { "InfernoFront" } );
	}
}
