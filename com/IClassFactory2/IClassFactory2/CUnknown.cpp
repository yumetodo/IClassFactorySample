// CUnknown.cpp : CCUnknown ‚ÌŽÀ‘•

#include "stdafx.h"
#include "CUnknown.h"
#include <iostream>


// CCUnknown

STDMETHODIMP CCUnknown::Method()
{
	std::cout << "CCUnknown::Method" << std::endl;
	return S_OK;
}
