#pragma once
#include"Ronin.h"

class Socket{
private:
	const int address_family = AF_INET;
	const int type = SOCK_STREAM;
	const int protocol = IPPROTO_TCP;
public:
	int port;
	char* host;
	SOCKET sock;

	bool Connect();
	void Recv(void(char* data));
	void Send(char* data);
	bool Close();
	bool isConnect();
};