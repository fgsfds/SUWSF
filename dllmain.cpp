// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <iostream>
#include <Psapi.h>
#include "external/IniReader/IniReader.h"
#include <algorithm>
#include "AspectRatio.h"
#include "dllmain.h"
#include "Logging.h"

void Init()
{
	DBOUT(APPNAME << " VERSION " << VERSION << " INITIALIZED.");
	AspectRatio::Init();
}

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)Init, NULL, NULL, NULL);
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}