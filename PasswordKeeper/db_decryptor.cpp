#include "cryptor.h"
#include "blowfish.h"
#include "XorStr.h"

unsigned char* passwordDb = nullptr;
int passwordDbSize = 0;

bool decrypt_db()
{
	char* pKey = XorStr("3FM*b1$USgf}srGR7bINm8OR52oer6n1eBe#%64$wOlLmK5");
	char* iv = XorStr("CisCntu");

	BLOWFISH bf(reinterpret_cast<byte*>(pKey), 48);
	bf.SetIV(reinterpret_cast<byte*>(iv));

	FILE* password_db = nullptr;
	errno_t errors = fopen_s(&password_db, XorStr("passwords.db"), XorStr("rb"));
	if(errors || !password_db)
		return false;

	byte* passwords = new byte[960];
	if(fread_s(passwords, 960, 1, 960, password_db) != 960)
	{
		delete[] passwords;
		fclose(password_db);
		return false;
	}

	passwordDb = bf.Decrypt_CBC(passwords, 960, &passwordDbSize);
	delete[] passwords;
	fclose(password_db);
	return true;
}