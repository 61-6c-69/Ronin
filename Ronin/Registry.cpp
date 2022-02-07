#include "Registry.h"

bool Registry::CreateRegistry(){
	HKEY key;
	DWORD ret;
	ret = RegCreateKey(
		this->hKey,
		this->subKey,
		&key
		);
	if (ret != ERROR_SUCCESS){
		return false;
	}

	RegCloseKey(key);

	return true;
}

vector<string> Registry::ListRegistry(){
	vector<string> list;
	HKEY key;
	DWORD ret;
	DWORD subkey;
	DWORD subkey_len;
	DWORD subvalues;
	DWORD subvalues_len;

	ret = RegOpenKey(
		this->hKey,
		this->subKey,
		&key
		);
	if (ret != ERROR_SUCCESS){
		return list;
	}

	ret = RegQueryInfoKey(
		key,
		NULL,
		NULL,
		NULL,
		&subkey,
		&subkey_len,
		NULL,
		&subvalues,
		&subvalues_len,
		NULL,
		NULL,
		NULL
		);

	if (ret != ERROR_SUCCESS){
		return list;
	}

	//subkeys
	char sub[256];
	DWORD sub_len;

	for (
		int i = 0;
		i < subkey;
	i++
		){
		sub_len = sizeof(sub);
		RegEnumKey(
			key,
			i,
			sub,
			subkey_len
			);
		list.push_back(sub);
	}

	//subvalue
	char val[256];
	DWORD val_len;

	for (
		int i = 0;
		i<subvalues;
	i++
		){
		val_len = sizeof(val);
		ret = RegEnumValue(
			key,
			i,
			val,
			&val_len,
			NULL,
			NULL,
			NULL,
			NULL
			);
		if (ret == ERROR_SUCCESS){
			list.push_back(val);
		}
	}

	RegCloseKey(key);

	return list;
}


char * Registry::ReadRegistry(LPCSTR valueName){
	HKEY key;
	DWORD ret;
	TCHAR data[256];
	DWORD data_len = sizeof(data);

	ret = RegOpenKey(
		this->hKey,
		this->subKey,
		&key
		);
	if (ret != ERROR_SUCCESS){
		return "";
	}

	ret = RegQueryValueEx(
		key,
		valueName,
		NULL,
		NULL, (LPBYTE)&data,
		&data_len
		);
	if (ret != ERROR_SUCCESS){
		return "";
	}

	char * ret_Data = new char[data_len];
	for (
		int i = 0;
		i < (int)data_len;
	i++
		){
		ret_Data[i] = data[i];
	}
	RegCloseKey(key);

	return ret_Data;
}

bool Registry::UpdateRegistry(LPCSTR key_value, LPCSTR value, DWORD type){
	HKEY key;
	DWORD ret;

	ret = RegOpenKey(
		this->hKey,
		this->subKey,
		&key
		);
	if (ret != ERROR_SUCCESS){
		return false;
	}

	ret = RegSetValueEx(
		key,
		key_value,
		0,
		type,
		(LPBYTE)value,
		strlen(value)
		);

	if (ret != ERROR_SUCCESS){
		return false;
	}

	RegCloseKey(key);
	return true;
}


