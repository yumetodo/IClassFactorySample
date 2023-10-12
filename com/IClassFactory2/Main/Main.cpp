// Main.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include  <IClassFactory2_i.h>
#include <IClassFactory2_i.c>
#include <iostream>
int main()
{
	ICUnknown* pUnknown = NULL;

	CoInitialize(NULL);

#if 1
	IClassFactory* pcf = NULL;
	std::cout << "call CoGetClassObject" << std::endl;
	HRESULT hr1 = CoGetClassObject(CLSID_CUnknown, CLSCTX_INPROC_SERVER, 0, IID_IClassFactory, reinterpret_cast<void**>(&pcf));
	if (FAILED(hr1)) {
		_tprintf(_T("CoGetClassObject failed!\n"));
		CoUninitialize();
		return 0;
	}
	std::cout << "call pcf->CreateInstance" << std::endl;
	HRESULT hr2 = pcf->CreateInstance(NULL, IID_ICUnknown, reinterpret_cast<void**>(&pUnknown));
	std::cout << "call pcf->Release" << std::endl;
	pcf->Release();
	if (FAILED(hr2)) {
		_tprintf(_T("CreateInstance failed!\n"));
		CoUninitialize();
		return 0;
	}
#else
	std::cout << "call CoCreateInstance" << std::endl;
	HRESULT hr = CoCreateInstance(CLSID_CUnknown, NULL, CLSCTX_INPROC_SERVER, IID_ICUnknown, (void **)&pUnknown);
	if (FAILED(hr)) {
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

