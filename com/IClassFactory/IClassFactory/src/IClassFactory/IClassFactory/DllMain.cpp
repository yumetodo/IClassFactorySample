#include <cstdio>		// �W�����o��
#include <tchar.h>		// TCHAR�Ή�
static long g_lLock = 0;	// ���b�N
#include "DllMain.h"	// DllMain�̐錾
#include "Unknown.h"		// Unknown�̐錾
#include "ClassFactory.h"	// ClassFactory�̐錾

#include <cstdio>		// �W�����o��
#include <tchar.h>		// TCHAR�Ή�

static CClassFactory g_ClassFactory;	// ClassFactory�I�u�W�F�N�g
HMODULE g_hModule = NULL;

extern "C" BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved){
	g_hModule = hinstDLL;
	return TRUE;
}
STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID *ppv){
	if (rclsid == CLSID_CUnknown){
		return g_ClassFactory.QueryInterface(riid, ppv);
	}
	else{
		*ppv =NULL;
		return CLASS_E_CLASSNOTAVAILABLE;
	}
}
void LockModule(){
	InterlockedIncrement(&g_lLock);
}
void UnlockModule(){
	InterlockedDecrement(&g_lLock);
}
STDAPI DllCanUnloadNow(void){
	return (g_lLock == 0) ? S_OK : S_FALSE;
}
STDAPI DllRegisterServer(void){
	TCHAR tszModulePath[MAX_PATH];
	HKEY hKey;
	long e;
	GetModuleFileName(g_hModule, tszModulePath, sizeof(tszModulePath) / sizeof(TCHAR));
	e = RegCreateKeyEx(HKEY_CLASSES_ROOT, _T("CLSID\\{94C0873F-A3E3-4d48-AECB-5B58DBED45FF}"), 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, NULL);
	if (e != ERROR_SUCCESS){
		return S_FALSE;
	}
	e = RegSetValueEx(hKey, NULL, 0, REG_SZ, (BYTE *)_T("IClassFactory"), (lstrlen(_T("IClassFactory")) + 1) * sizeof(TCHAR));
	if (e != ERROR_SUCCESS){
		RegCloseKey(hKey);
		return S_FALSE;
	}
	e = RegCreateKeyEx(HKEY_CLASSES_ROOT, _T("CLSID\\{94C0873F-A3E3-4d48-AECB-5B58DBED45FF}\\InprocServer32"), 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, NULL);
	if (e != ERROR_SUCCESS){
		return S_FALSE;
	}
	e = RegSetValueEx(hKey, NULL, 0, REG_SZ, (BYTE *)tszModulePath, (lstrlen(tszModulePath) + 1) * sizeof(TCHAR));
	if (e != ERROR_SUCCESS){
		RegCloseKey(hKey);
		return S_FALSE;
	}
	e = RegCreateKeyEx(HKEY_CLASSES_ROOT, _T("CLSID\\{94C0873F-A3E3-4d48-AECB-5B58DBED45FF}\\InprocServer32"), 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, NULL);
	if (e != ERROR_SUCCESS){
		return S_FALSE;
	}
	e = RegSetValueEx(hKey, _T("ThreadingModel"), 0, REG_SZ, (BYTE *)_T("Apartment"), (lstrlen(_T("Apartment")) + 1) * sizeof(TCHAR));
	if (e != ERROR_SUCCESS){
		RegCloseKey(hKey);
		return S_FALSE;
	}
	e = RegCreateKeyEx(HKEY_CLASSES_ROOT, _T("CLSID\\{94C0873F-A3E3-4d48-AECB-5B58DBED45FF}\\ProgID"), 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, NULL);
	if (e != ERROR_SUCCESS){
		return S_FALSE;
	}
	e = RegSetValueEx(hKey, NULL, 0, REG_SZ, (BYTE *)_T("IClassFactory.CClassFactory"), (lstrlen(_T("IClassFactory.CClassFactory")) + 1) * sizeof(TCHAR));
	if (e != ERROR_SUCCESS){
		RegCloseKey(hKey);
		return S_FALSE;
	}
	return S_OK;
}
STDAPI DllUnregisterServer(void){

	RegDeleteKey(HKEY_CLASSES_ROOT, _T("CLSID\\{94C0873F-A3E3-4d48-AECB-5B58DBED45FF}\\ProgID"));
	RegDeleteKey(HKEY_CLASSES_ROOT, _T("CLSID\\{94C0873F-A3E3-4d48-AECB-5B58DBED45FF}\\InprocServer32"));
	RegDeleteKey(HKEY_CLASSES_ROOT, _T("CLSID\\{94C0873F-A3E3-4d48-AECB-5B58DBED45FF}"));

	return S_OK;
}