# Fix Long Number Crash
Satisfactory mod to fix an engine bug that causes a crash when entering very long numbers in a numeric entry box

## ficsit.app page
https://ficsit.app/mod/FixLongNumberCrash

## Description
When entering very large numbers in a numeric entry box, the game tends to crash with an integer divide-by-zero exception. This mod fixes this problem by patching the function that crashes. It is the same fix from https://github.com/EpicGames/UnrealEngine/pull/11663 but packaged into a mod.

This mod also prevents crashes in the editor, but requires manually reconstructing the patched code as the UE license does not allow publishing long pieces of engine code. See instructions in source code to work around this.
