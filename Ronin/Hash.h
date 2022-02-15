#pragma once
#include"Crypto.h"
class Hash{
private:
	Crypto crypto;
	char* str;

	void setHashInfo(int size, DWORD calg, DWORD prov = PROV_RSA_FULL){
		this->crypto.buf_size = size;
		this->crypto.hash_calg = calg;
		this->crypto.hash_prov = prov;
	}

public:
	Hash(char* str){
		this->str = str;
	}

	Hash& md5(){
		this->setHashInfo(16, CALG_MD5);
		return *this;
	}

	Hash& sha1(){
		this->setHashInfo(20, CALG_SHA1);
		return *this;
	}

	Hash& sha256(){
		this->setHashInfo(32, CALG_SHA_256);
		return *this;
	}

	char* get(){
		return crypto.Create(this->str);
	}
};