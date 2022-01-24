#include"Socket.h"

bool Socket::Connect(){
	WSADATA wsa;
	struct sockaddr_in addr;

	if (WSAStartup(MAKEWORD(2, 2), &wsa) == SOCKET_ERROR){
		return false;
	}

	this->sock = socket(this->address_family, this->type, this->protocol);
	if (this->sock == INVALID_SOCKET){
		return false;
	}

	addr.sin_addr.s_addr = inet_addr(this->host == NULL ? SERVER_IP : this->host);
	addr.sin_family = this->address_family;
	addr.sin_port = htons(this->port == 0 ? SERVER_PORT : this->port);

	int con = connect(this->sock, (struct sockaddr*)&addr, sizeof(addr));
	if (con  == SOCKET_ERROR){
		return false;
	}

	return true;
}

