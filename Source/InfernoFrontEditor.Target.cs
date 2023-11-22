// Copyright Epidemic Studios

using UnrealBuildTool;
using System.Collections.Generic;

public class InfernoFrontEditorTarget : TargetRules
{
	public InfernoFrontEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V4;

		ExtraModuleNames.AddRange( new string[] { "InfernoFront" } );
	}
}
