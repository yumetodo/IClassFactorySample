// CUnknown.h : CCUnknown の宣言

#pragma once
#include "resource.h"       // メイン シンボル



#include "IClassFactory2_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "DCOM の完全サポートを含んでいない Windows Mobile プラットフォームのような Windows CE プラットフォームでは、単一スレッド COM オブジェクトは正しくサポートされていません。ATL が単一スレッド COM オブジェクトの作成をサポートすること、およびその単一スレッド COM オブジェクトの実装の使用を許可することを強制するには、_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA を定義してください。ご使用の rgs ファイルのスレッド モデルは 'Free' に設定されており、DCOM Windows CE 以外のプラットフォームでサポートされる唯一のスレッド モデルと設定されていました。"
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
