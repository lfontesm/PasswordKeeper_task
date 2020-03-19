#include "Initer.h"
#include "cryptor.h"

#include <iostream>
#include <string>

//bool decrypt_password(DWORD messageBoxAdr, DWORD mallocAdr, DWORD freeAdr, const char* key, const char* successTitle, const char* errorMessage)
//{
//	int(__stdcall * pMessageBox)(HANDLE, LPCSTR, LPCSTR, UINT) = (int(__stdcall*)(HANDLE, LPCSTR, LPCSTR, UINT))(messageBoxAdr);
//	void* (_cdecl * pMalloc)(size_t) = (void* (_cdecl*)(size_t))(mallocAdr);
//	void(_cdecl * pFree)(void*) = (void(_cdecl *)(void*))(freeAdr);
//
//
//	char* pKey = static_cast<char*>(pMalloc(16));
//	unsigned char* flag = static_cast<unsigned char*>(pMalloc(24));
//	
//	if (!pKey)
//		return false;
//
//	if(!flag)
//	{
//		pFree(pKey);
//		return false;
//	}
//
//	flag[0] = 0x15;
//	flag[1] = 0x1d;
//	flag[2] = 0x01;
//	flag[3] = 0x10;
//	flag[4] = 0x3f;
//	flag[5] = 0x07;
//	flag[6] = 0x15;
//	flag[7] = 0x68;
//	flag[8] = 0x18;
//	flag[9] = 0x04;
//	flag[10] = 0x43;
//	flag[11] = 0x39;
//	flag[12] = 0x19;
//	flag[13] = 0x1c;
//	flag[14] = 0x57;
//	flag[15] = 0x37;
//	flag[16] = 0x55;
//	flag[17] = 0x16;
//	flag[18] = 0x54;
//	flag[19] = 0x34;
//	flag[20] = 0x11;
//	flag[21] = 0x2a;
//	flag[22] = 0x1a;
//	flag[23] = 0x5f;
//
//	
//	pKey[0] = 'f' ^ 0x13;
//	pKey[1] = 'u' ^ 0x13;
//	pKey[2] = 'c' ^ 0x13;
//	pKey[3] = 'k' ^ 0x13;
//	pKey[4] = 'i' ^ 0x13;
//	pKey[5] = 'n' ^ 0x13;
//	pKey[6] = 'g' ^ 0x13;
//	pKey[7] = '_' ^ 0x13;
//	pKey[8] = 'm' ^ 0x13;
//	pKey[9] = '0' ^ 0x13;
//	pKey[10] = 'r' ^ 0x13;
//	pKey[11] = 'f' ^ 0x13;
//	pKey[12] = 'i' ^ 0x13;
//	pKey[13] = 'n' ^ 0x13;
//	pKey[14] = 'g' ^ 0x13;
//	pKey[15] = '\0' ^ 0x13;
//
//	for (int i = 0; i < 15; i++)
//	{
//		if (key[i] == '\0')
//		{
//			pMessageBox(nullptr, errorMessage, nullptr, 0);
//			pFree(pKey);
//			pFree(flag);
//			return false;
//		}
//
//		if ((pKey[i] ^ 0x13) != key[i])
//		{
//			pMessageBox(nullptr, errorMessage, nullptr, 0);
//			pFree(pKey);
//			pFree(flag);
//			return false;
//		}
//	}
//
//	for (int i = 0; i < 24; i++)
//	{
//		flag[i] ^= key[i % 16];
//	}
//
//	pMessageBox(nullptr, reinterpret_cast<LPCSTR>(flag), successTitle, 0);
//
//	pFree(pKey);
//	pFree(flag);
//	
//	return true;
//}
//void stub() { }


//fucking_m0rfing
//shb{ Vir7u41_pr073c7_xD }

int main()
{
	initialization::load_libs();
	if (!decrypt_db())
	{
		std::cout << "please, check passwords.db file" << std::endl;
		return 0;
	}
	
	std::cout << "Welcome to Super Password Keeper" << std::endl;
	std::cout << "Enter password for decryption->";
	std::string password;
	std::getline(std::cin, password);
	decrypt_flag(password.c_str());

	system("pause");
	return 0;
}