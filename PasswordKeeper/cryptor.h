#pragma once

void decrypt_flag(const char* password);
bool decrypt_db();

extern unsigned char* passwordDb;
extern int passwordDbSize;