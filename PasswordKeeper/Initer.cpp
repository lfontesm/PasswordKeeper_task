#include <Windows.h>
#include <cstdio>

#include "lazy_importer.hpp"
#include "XorStr.h"
#include "Initer.h"


namespace initialization
{
	bool load_libs()
	{
		const auto pLoadLibrary = LI_FN(LoadLibraryA).get();
		if(!pLoadLibrary)
			return false;

		pLoadLibrary(XorStr("user32.dll"));
		return true;
		
	}
	
}
