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

char* SystemInfo::GetWinDir(){
	char* gwd = new char[MAX_PATH];
	UINT gwd_size = MAX_PATH;
	if (!GetWindowsDirectory(gwd, gwd_size)){
		return NULL;
	}
	return gwd;
}

char SystemInfo::GetWinDrive(){
	return SystemInfo::GetWinDir()[0];
}