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
		Append = ios::app
	};

	SysFile& Open(char* path, FILE_FLAG ff);

	size_t getLen();
	char* ReadFile();
	void WriteFile(char* data);
	void Close();


	bool Exists(){
		return this->file_exists;
	}
	size_t Len(){
		return this->file_len;
	}
	bool isOpen(){
		return this->file.is_open();
	}
	~SysFile(){
		this->Close();
	}
};