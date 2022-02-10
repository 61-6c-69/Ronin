#pragma once
#include"Crypto.h"
class Hash{
public:
	//md5
	static char* md5(char* str){
		Crypto ca;
		ca.buf_size = 16;
		ca.hash_calg = CALG_MD5;
		ca.hash_prov = PROV_RSA_FULL;
		return ca.Create(str);
	}

	//sha1
	static char* sha1(char* str){
		Crypto ca;
		ca.buf_size = 20;
		ca.hash_calg = CALG_SHA1;
		ca.hash_prov = PROV_RSA_FULL;
		return ca.Create(str);
	}

	//sha256
	static char* sha256(char* str){
		Crypto ca;
		ca.buf_size = 32;
		ca.hash_calg = CALG_SHA_256;
		ca.hash_prov = PROV_RSA_FULL;
		return ca.Create(str);
	}

};