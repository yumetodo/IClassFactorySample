// dllmain.cpp : DllMain �̎����ł��B

#include "stdafx.h"
#include "resource.h"
#include "IClassFactory2_i.h"
#include "dllmain.h"

CIClassFactory2Module _AtlModule;

// DLL �G���g�� �|�C���g
extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	hInstance;
	return _AtlModule.DllMain(dwReason, lpReserved); 
}
