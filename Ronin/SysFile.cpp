#include"SysFile.h"

SysFile& SysFile::Open(char* path, SysFile::FILE_FLAG ff){
	this->file.open(path, ff);
	this->file_exists = this->file.fail() ? false : true;
	return *this;
}

size_t SysFile::getLen(){
	if (!this->file_exists){
		return 0;
	}

	if (this->file_len == 0){
		this->file.seekg(0, this->file.end);
		this->file_len = this->file.tellg();
		this->file.seekg(0, this->file.beg);
	}

	return this->file_len;
}

char* SysFile::ReadFile(){
	if (!this->file_exists){
		return NULL;
	}

	char* buf = new char[this->getLen()+1];
	this->file.read(buf, this->getLen());
	//buf[this->file.gcount()] = '\0';

	return buf;
}