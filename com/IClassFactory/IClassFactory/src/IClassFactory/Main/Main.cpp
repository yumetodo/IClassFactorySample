// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <cstdio>		// 標準入出力
#include <tchar.h>		// TCHAR対応
#include <iostream>
#include "IUnknown_.h"	// MIDL生成
#include "IUnknown__i.c"	// GUID

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	IUnknown_* pUnknown = NULL;

	CoInitialize(NULL);

#if 0
	IClassFactory* pcf = NULL;
	std::cout << "call CoGetClassObject" << std::endl;
	HRESULT hr1 = CoGetClassObject(CLSID_CUnknown, CLSCTX_INPROC_SERVER, 0, IID_IClassFactory, reinterpret_cast<void**>(&pcf));
	if (FAILED(hr1)){
		_tprintf(_T("CoGetClassObject failed!\n"));
		CoUninitialize();
		return 0;
	}
	std::cout << "call pcf->CreateInstance" << std::endl;
	HRESULT hr2 = pcf->CreateInstance(NULL, IID_IUnknown_, reinterpret_cast<void**>(&pUnknown));
	std::cout << "call pcf->Release" << std::endl;
	pcf->Release();
	if (FAILED(hr2)){
		_tprintf(_T("CreateInstance failed!\n"));
		CoUninitialize();
		return 0;
	}
#else
	std::cout << "call CoCreateInstance" << std::endl;
	HRESULT hr = CoCreateInstance(CLSID_CUnknown, NULL, CLSCTX_INPROC_SERVER, IID_IUnknown_, (void **)&pUnknown);
	if (FAILED(hr)){
		_tprintf(_T("CoCreateInstance failed!\n"));
		CoUninitialize();
		return 0;
	}
#endif
	std::cout << "call pUnknown->Method" << std::endl;
	pUnknown->Method();
	std::cout << "call pUnknown->Release" << std::endl;
	pUnknown->Release();

	CoUninitialize();

	// プログラムの終了
	return 0;

}