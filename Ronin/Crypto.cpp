#include"Crypto.h"

char* Crypto::Create(char* text){
	HCRYPTPROV hprov;
	HCRYPTHASH hhash;
	char *hex = "0123456789abcdef";
	DWORD hsize;
	BYTE* hash = new BYTE[this->buf_size];
	char* str_hash = new char[this->buf_size + 1];

	if (!CryptAcquireContext(&hprov, NULL, MS_DEF_PROV, this->hash_prov, CRYPT_VERIFYCONTEXT)){
		return NULL;
	}

	if (!CryptCreateHash(hprov, this->hash_calg, 0, 0, &hhash)){
		return NULL;
	}

	if (!CryptHashData(hhash, (BYTE*)text, strlen(text), 0)){
		return NULL;
	}

	if (!CryptGetHashParam(hhash, HP_HASHVAL, hash, &hsize, 0)){
		return NULL;
	}
	
	for (int i = 0; i < hsize; i++){
		str_hash[i * 2] = hex[hash[i] >> 4];
		str_hash[(i * 2) + 1] = hex[hash[i] & 0xf];
	}

	CryptDestroyHash(hhash);
	CryptReleaseContext(hprov, 0);

	return str_hash;
}