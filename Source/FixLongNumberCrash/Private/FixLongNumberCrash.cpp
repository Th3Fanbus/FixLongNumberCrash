// Copyright Epic Games, Inc. All Rights Reserved.

#include "FixLongNumberCrash.h"
#include "Internationalization/FastDecimalFormat.h"
#include "Patching/NativeHookManager.h"

namespace Th3EngineHooks
{
	namespace FastDecimalFormat
	{
		namespace Internal
		{
                        /*
                         * UE license agreement disallows publishing the full contents of this file. However, you can reconstruct it as follows:
                         *
                         * 1. Locate the following file: UE-5.2.1-CSS-60\Engine\Source\Runtime\Core\Private\Internationalization\FastDecimalFormat.cpp
                         * 2. Copy about 500 lines from the `FastDecimalFormat::Internal` namespace: the `FractionalToString` function and its dependencies
                         * 3. Paste the lines you copied right after this comment, the function call in the hook should be happy
                         * 4. Apply fix from https://github.com/EpicGames/UnrealEngine/pull/11663 to the copied code
                         * 5. Try to build, it should work
                         */
		}
	}
}

static void Hook_FractionalToString(
	TCallScope<void(__cdecl*)(const double, const FDecimalNumberFormattingRules&, FNumberFormattingOptions, FString&)>& scope,
	const double InVal,
	const FDecimalNumberFormattingRules& InFormattingRules,
	FNumberFormattingOptions InFormattingOptions,
	FString& OutString
)
{
	Th3EngineHooks::FastDecimalFormat::Internal::FractionalToString(InVal, InFormattingRules, InFormattingOptions, OutString);
	scope.Cancel();
}

void FFixLongNumberCrashModule::StartupModule()
{
	SUBSCRIBE_METHOD(FastDecimalFormat::Internal::FractionalToString, &Hook_FractionalToString);
}

void FFixLongNumberCrashModule::ShutdownModule()
{
}

IMPLEMENT_MODULE(FFixLongNumberCrashModule, FixLongNumberCrash)