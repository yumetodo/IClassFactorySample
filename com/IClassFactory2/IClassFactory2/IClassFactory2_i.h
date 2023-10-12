

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Thu Oct 12 11:37:14 2023
 */
/* Compiler settings for IClassFactory2.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __IClassFactory2_i_h__
#define __IClassFactory2_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ICUnknown_FWD_DEFINED__
#define __ICUnknown_FWD_DEFINED__
typedef interface ICUnknown ICUnknown;

#endif 	/* __ICUnknown_FWD_DEFINED__ */


#ifndef __CUnknown_FWD_DEFINED__
#define __CUnknown_FWD_DEFINED__

#ifdef __cplusplus
typedef class CUnknown CUnknown;
#else
typedef struct CUnknown CUnknown;
#endif /* __cplusplus */

#endif 	/* __CUnknown_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __ICUnknown_INTERFACE_DEFINED__
#define __ICUnknown_INTERFACE_DEFINED__

/* interface ICUnknown */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ICUnknown;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4670985E-D857-46F5-9FFB-83B5032852DA")
    ICUnknown : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Method( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICUnknownVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICUnknown * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICUnknown * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICUnknown * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICUnknown * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICUnknown * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICUnknown * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICUnknown * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *Method )( 
            ICUnknown * This);
        
        END_INTERFACE
    } ICUnknownVtbl;

    interface ICUnknown
    {
        CONST_VTBL struct ICUnknownVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICUnknown_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICUnknown_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICUnknown_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICUnknown_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICUnknown_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICUnknown_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICUnknown_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ICUnknown_Method(This)	\
    ( (This)->lpVtbl -> Method(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICUnknown_INTERFACE_DEFINED__ */



#ifndef __IClassFactory2Lib_LIBRARY_DEFINED__
#define __IClassFactory2Lib_LIBRARY_DEFINED__

/* library IClassFactory2Lib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_IClassFactory2Lib;

EXTERN_C const CLSID CLSID_CUnknown;

#ifdef __cplusplus

class DECLSPEC_UUID("4F1586EA-BF58-423D-81D9-19DD6248DFE4")
CUnknown;
#endif
#endif /* __IClassFactory2Lib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


