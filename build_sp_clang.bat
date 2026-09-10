@echo off
clang-cl /nologo /w /Od /Z7 /MTd -m32 /D_DEBUG /DWIN32 /DC_ONLY /DGAME_HARD_LINKED /DREF_HARD_LINKED ^
	-fno-strict-aliasing -fcommon -Wno-implicit-int -Wno-implicit-function-declaration -Wno-incompatible-pointer-types ^
	-Wno-int-conversion /Fedebug\quake2.exe q2sp.c ^
	/link /DEBUG /SUBSYSTEM:WINDOWS winmm.lib wsock32.lib kernel32.lib user32.lib gdi32.lib
