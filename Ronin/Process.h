#pragma once
#include"Ronin.h"

class Process{
private:
	FILE* pipe;

public:
	enum  OpenMode
	{
		READ,
		WRITE
	};
	bool Open(char*, OpenMode);
	void Write(char*);
	void Recv(void(*callback)(char*));
	bool Close();
};
