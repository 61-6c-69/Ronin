#pragma once
#include "Ronin.h"
class Registry{
public:
	void setRegistryKey(HKEY key){
		this->hKey = key;
	};
	void setRegistrySubkey(LPCSTR subKey){
		this->subKey = subKey;
	}

	bool CreateRegistry();
	vector<string> ListRegistry();
	char * ReadRegistry(LPCSTR valueName);
	bool UpdateRegistry(LPCSTR key_value, LPCSTR value, DWORD type);
private:
	HKEY hKey;
	LPCSTR subKey;
};