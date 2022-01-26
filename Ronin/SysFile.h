#pragma once
#include"Ronin.h"

class SysFile{
protected:
	fstream file;
	bool file_exists;
	size_t file_len;

public:
	enum FILE_FLAG{
		Read = ios::in,
		Write = ios::out,
		Read_Write = ios::ate,
		Append = ios::ate
	};

	SysFile& Open(char* path, FILE_FLAG ff);

	size_t getLen();
	char* ReadFile();
	//void Write(char* data);
};