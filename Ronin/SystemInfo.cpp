#include"SystemInfo.h"

char* SystemInfo::ComputerName(){
	char* pcname = new char[MAX_COMPUTERNAME_LENGTH];
	DWORD pcname_size = MAX_COMPUTERNAME_LENGTH;
	if (!GetComputerNameA(pcname, &pcname_size)){
		return NULL;
	}
	return pcname;
}

char* SystemInfo::GetExecutablePath(){
	char* exp = new char[MAX_PATH];
	DWORD exp_size = MAX_PATH;
	if (!GetModuleFileName(NULL, exp, exp_size)){
		return NULL;
	}
	return exp;
}