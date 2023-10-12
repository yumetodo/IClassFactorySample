// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <cstdio>		// �W�����o��
#include <tchar.h>		// TCHAR�Ή�
#include <iostream>
#include "IUnknown_.h"	// MIDL����
#include "IUnknown__i.c"	// GUID

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

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

	// �v���O�����̏I��
	return 0;

}