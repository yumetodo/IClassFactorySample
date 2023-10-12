// CUnknown.cpp : CCUnknown ‚ÌŽÀ‘•

#include "stdafx.h"
#include "CUnknown.h"
#include <iostream>

// CCUnknown

CCUnknown::CCUnknown()
{
	std::cout << "CCUnknown::CCUnknown" << std::endl;
}


//DECLARE_PROTECT_FINAL_CONSTRUCT()

void CCUnknown::InternalFinalConstructAddRef()
{
	std::cout << "CCUnknown::InternalFinalConstructAddRef" << std::endl;
	InternalAddRef();
}

void CCUnknown::InternalFinalConstructRelease()
{
	std::cout << "CCUnknown::InternalFinalConstructRelease" << std::endl;
	InternalRelease();
}

HRESULT CCUnknown::FinalConstruct()
{
	std::cout << "CCUnknown::FinalConstruct" << std::endl;
	return S_OK;
}

void CCUnknown::FinalRelease()
{
	std::cout << "CCUnknown::FinalRelease" << std::endl;
}

STDMETHODIMP CCUnknown::Method()
{
	std::cout << "CCUnknown::Method" << std::endl;
	return S_OK;
}
