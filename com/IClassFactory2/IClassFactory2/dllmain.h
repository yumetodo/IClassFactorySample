// dllmain.h : モジュール クラスの宣言です。

class CIClassFactory2Module : public ATL::CAtlDllModuleT< CIClassFactory2Module >
{
public :
	DECLARE_LIBID(LIBID_IClassFactory2Lib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_ICLASSFACTORY2, "{E75247A8-8E8E-4EBE-8118-2C4497D046E0}")
};

extern class CIClassFactory2Module _AtlModule;
