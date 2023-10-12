// CUnknown.h : CCUnknown �̐錾

#pragma once
#include "resource.h"       // ���C�� �V���{��



#include "IClassFactory2_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "DCOM �̊��S�T�|�[�g���܂�ł��Ȃ� Windows Mobile �v���b�g�t�H�[���̂悤�� Windows CE �v���b�g�t�H�[���ł́A�P��X���b�h COM �I�u�W�F�N�g�͐������T�|�[�g����Ă��܂���BATL ���P��X���b�h COM �I�u�W�F�N�g�̍쐬���T�|�[�g���邱�ƁA����т��̒P��X���b�h COM �I�u�W�F�N�g�̎����̎g�p�������邱�Ƃ���������ɂ́A_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ���`���Ă��������B���g�p�� rgs �t�@�C���̃X���b�h ���f���� 'Free' �ɐݒ肳��Ă���ADCOM Windows CE �ȊO�̃v���b�g�t�H�[���ŃT�|�[�g�����B��̃X���b�h ���f���Ɛݒ肳��Ă��܂����B"
#endif

using namespace ATL;


// CCUnknown

class ATL_NO_VTABLE CCUnknown :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CCUnknown, &CLSID_CUnknown>,
	public IDispatchImpl<ICUnknown, &IID_ICUnknown, &LIBID_IClassFactory2Lib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CCUnknown();

DECLARE_REGISTRY_RESOURCEID(IDR_CUNKNOWN)

DECLARE_NOT_AGGREGATABLE(CCUnknown)

BEGIN_COM_MAP(CCUnknown)
	COM_INTERFACE_ENTRY(ICUnknown)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

	//DECLARE_PROTECT_FINAL_CONSTRUCT()
	void InternalFinalConstructAddRef();
	void InternalFinalConstructRelease();

	HRESULT FinalConstruct();

	void FinalRelease();

public:

	STDMETHODIMP Method() override;


};

OBJECT_ENTRY_AUTO(__uuidof(CUnknown), CCUnknown)
