#include"SysFile.h"

SysFile& SysFile::Open(char* path, SysFile::FILE_FLAG ff){
	if (this->file.is_open()){
		this->Close();
	}
	this->file.open(path, ff);
	this->file_exists = this->file.fail() ? false : true;
	return *this;
}

size_t SysFile::getLen(){
	if (!this->file.is_open()){
		return 0;
	}

	if (this->file_len == 0){
		this->file.seekp(0, ios::end);
		this->file_len = this->file.tellp();
		this->file.seekp(0, this->file.beg);
	}
	return this->file_len;
}

char* SysFile::ReadFile(){
	if (!this->file.is_open()){
		return NULL;
	}

	char* buf = new char[this->getLen()];
	this->file.read(buf, this->getLen());
	buf[this->file_len] = '\0';

	return buf;
}

void SysFile::WriteFile(char* data, size_t size){
	if (!this->file.is_open()){
		return;
	}

	this->file.write(data, size == 0 ? strlen(data) : size);
	this->file.flush();
}

void SysFile::Close(){
	this->file.close();
}

