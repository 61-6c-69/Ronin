#pragma once
#include"Ronin.h"

class Crypto{
public:
	int buf_size;

	DWORD hash_prov; //ext: PROV_RSA_FULL
	DWORD hash_calg; //ext: CALG_MD5

	char* Create(char* text);
};