#include"SystemInfo.h"

char* SystemInfo::ComputerName(){
	char* pcname = new char[MAX_COMPUTERNAME_LENGTH];
	DWORD pcname_size = MAX_COMPUTERNAME_LENGTH;
	if (!GetComputerNameA(pcname, &pcname_size)){
		return NULL;
	}
	return pcname;
}