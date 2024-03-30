// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class TableTopEditorTarget : TargetRules
{
	public TableTopEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V4;

		ExtraModuleNames.AddRange(new string[] { "TableTop" });
	}
}