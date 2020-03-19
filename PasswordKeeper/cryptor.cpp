#include <Windows.h>
#include "cryptor.h"

#include "lazy_importer.hpp"
#include "XorStr.h"

typedef void (*secret_fn)(DWORD messageBoxAdr, DWORD mallocAdr, DWORD freeAdr, const char* key, const char* successTitle, const char* errorMessage);

void decrypt_flag(const char* password)
{
	std::string errorMessage = std::string(XorStr("Invalid Password"));
	std::string successMessage = std::string(XorStr("Nice Job!"));
	DWORD messageBoxAdr = DWORD(LI_FN(MessageBoxA).get());
	DWORD mallocAdr = DWORD(LI_FN(malloc).get());
	DWORD freeAdr = DWORD(LI_FN(free).get());

	DWORD oldProtect = 0;
	const auto pVirtualProtect = LI_FN(VirtualProtect).get();

	pVirtualProtect(passwordDb, passwordDbSize, PAGE_EXECUTE_READWRITE, &oldProtect);
	(reinterpret_cast<secret_fn>(&passwordDb[0]))(messageBoxAdr, mallocAdr, freeAdr, password, successMessage.c_str(), errorMessage.c_str());
	pVirtualProtect(passwordDb, passwordDbSize, oldProtect, &oldProtect);
	
	LI_FN(memset).get()(passwordDb, 0, passwordDbSize);
	delete[] passwordDb;
}
