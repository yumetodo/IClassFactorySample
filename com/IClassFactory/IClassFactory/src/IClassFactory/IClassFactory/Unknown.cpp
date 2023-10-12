#include <cstdio>			// ïWèÄì¸èoóÕ
#include <tchar.h>			// TCHARëŒâû
#include "DllMain.h"	// DllMainÇÃêÈåæ
#include "Unknown.h"		// CUnknown
#include "IUnknown__i.c"	// GUID

CUnknown::CUnknown() : m_lRef(0){

	m_lRef = 1;

}

CUnknown::~CUnknown(){

}

STDMETHODIMP CUnknown::QueryInterface(REFIID riid, LPVOID *ppv){

	*ppv = NULL;

	if (riid == IID_IUnknown || riid == IID_IUnknown_){
		*ppv = static_cast<IUnknown_ *>(this);
	}
	else{
		return E_NOINTERFACE;
	}
	_tprintf(_T("CUnknown::QueryInterface!\n"));
	static_cast<IUnknown_ *>(*ppv)->AddRef();
	return S_OK;

}

STDMETHODIMP_(ULONG) CUnknown::AddRef(){

	LockModule();
	LONG res = InterlockedIncrement(&m_lRef);
	_tprintf(_T("CUnknown::AddRef, m_lRef=%ld\n"), res);
	return res;
}

STDMETHODIMP_(ULONG) CUnknown::Release(){

	LONG res = InterlockedDecrement(&m_lRef);
	if (res == 0){
		UnlockModule();
		delete this;
	}
	_tprintf(_T("CUnknown::Release, m_lRef=%ld\n"), res);
	return res;

}

STDMETHODIMP CUnknown::Method(void){

	_tprintf(_T("CUnknown::Method!\n"));
	return S_OK;

}