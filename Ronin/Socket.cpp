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


void Socket::Recv(void(*callback)(char*)){
	char* msg = new char[SERVER_RECV_BUFF_SIZE];
	int msg_size;

	while (true){
		//recv
		msg_size = recv(this->sock, msg, SERVER_RECV_BUFF_SIZE, 0);
		if (msg_size == SOCKET_ERROR){
			cout << "recv err"<<GetLastError();
			return;
		}

		msg[msg_size] = '\0';
		callback(msg);
	}
}

bool Socket::Send(char* data){
	int s = send(this->sock, data, strlen(data), 0);
	if (s == SOCKET_ERROR){
		return false;
	}

	return true;
}

void Socket::Close(){
	closesocket(this->sock);
	WSACleanup();
}

bool Socket::isConnect(){
	int e;
	int esize = sizeof(int);
	int er = getsockopt(this->sock, SOL_SOCKET, SO_ERROR, (char*)&e, &esize);
	if (er == SOCKET_ERROR){
		return false;
	}
	return true;
}