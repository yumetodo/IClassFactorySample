#include <cstdio>		// ïWèÄì¸èoóÕ
#include <tchar.h>		// TCHARëŒâû
#include "ClassFactory.h"
#include "Unknown.h"
#include "DllMain.h"	// DllMainÇÃêÈåæ

CClassFactory::CClassFactory() : m_lRef(0){

	m_lRef = 1;
	_tprintf(_T("CClassFactory::CClassFactory, m_lRef=%ld\n"), m_lRef);

}

CClassFactory::~CClassFactory(){
	_tprintf(_T("CClassFactory::~CClassFactory, m_lRef=%ld\n"), m_lRef);
}

STDMETHODIMP CClassFactory::QueryInterface(REFIID riid, LPVOID *ppv){

	*ppv = NULL;

	if (riid == IID_IUnknown || riid == IID_IClassFactory){
		*ppv = static_cast<IClassFactory *>(this);
	}
	else{
		return E_NOINTERFACE;
	}
	_tprintf(_T("CClassFactory::QueryInterface!\n"));
	AddRef();
	return S_OK;

}

STDMETHODIMP_(ULONG) CClassFactory::AddRef(){

	LockModule();
	const LONG res = InterlockedIncrement(&m_lRef);
	_tprintf(_T("CClassFactory::AddRef, m_lRef=%ld\n"), res);
	return res;
}

STDMETHODIMP_(ULONG) CClassFactory::Release(){

	LONG res = InterlockedDecrement(&m_lRef);
	if (res == 0){
		UnlockModule();
		delete this;
	}
	_tprintf(_T("CClassFactory::Release, m_lRef=%ld\n"), res);
	return res;

}

STDMETHODIMP CClassFactory::CreateInstance(IUnknown* pUnkOuter, REFIID riid, LPVOID *ppv){

	_tprintf(_T("CClassFactory::CreateInstance\n"));
	if (pUnkOuter != NULL){
		return CLASS_E_NOAGGREGATION;
	}
	CUnknown *pUnknown = new CUnknown();
	if (pUnknown == NULL){
		return E_OUTOFMEMORY;
	}
	HRESULT hr = pUnknown->QueryInterface(riid, ppv);
	pUnknown->Release();
	return hr;

}

STDMETHODIMP CClassFactory::LockServer(BOOL bLock){

	_tprintf(_T("CClassFactory::LockServer\n"));
	if (bLock){
		LockModule();
	}
	else{
		UnlockModule();
	}
	return S_OK;

}