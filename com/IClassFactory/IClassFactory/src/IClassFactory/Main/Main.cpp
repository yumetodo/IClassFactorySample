// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <cstdio>		// �W�����o��
#include <tchar.h>		// TCHAR�Ή�

#include "IUnknown_.h"	// MIDL����
#include "IUnknown__i.c"	// GUID

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	IUnknown_* pUnknown = NULL;

	CoInitialize(NULL);

	HRESULT hr = CoCreateInstance(CLSID_CUnknown, NULL, CLSCTX_INPROC_SERVER, IID_IUnknown_, (void **)&pUnknown);
	if (FAILED(hr)){
		_tprintf(_T("CoCreateInstance failed!\n"));
		CoUninitialize();
		return 0;
	}

	pUnknown->Method();

	pUnknown->Release();

	CoUninitialize();

	// �v���O�����̏I��
	return 0;

}