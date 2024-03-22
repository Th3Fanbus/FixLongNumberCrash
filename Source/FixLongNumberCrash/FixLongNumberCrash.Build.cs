using UnrealBuildTool;
using System.IO;
using System;

public class FixLongNumberCrash : ModuleRules
{
	public FixLongNumberCrash(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        bUseUnity = false;

        PublicDependencyModuleNames.AddRange(new string[] {
            "Core", "CoreUObject",
            "Engine",
            "AssetRegistry",
            "SlateCore", "Slate", "UMG",
            "RenderCore",
            "Json", "JsonUtilities",
            "DummyHeaders",
            "FactoryGame", "SML"
        });
    }
}
