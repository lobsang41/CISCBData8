// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class BigDataVR : ModuleRules
{
	public BigDataVR(TargetInfo Target)
	{
		
        PublicIncludePaths.AddRange(new string[] { "ProceduralMeshComponent/Public", "ProceduralMeshComponent/Classes" });

	    PublicDependencyModuleNames.AddRange(new string[] {"Core", "CoreUObject", "Engine", "InputCore", "RHI", "RenderCore", "ShaderCore", "ProceduralMeshComponent"});
	}
}
