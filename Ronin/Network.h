#pragma once
#include"Socket.h"
#include"json.h"
#include"CommandMap.h"

class Network{
private:
	Socket socket;

public:
	static Network& Init(){
		static Network instance;
		return instance;
	}

	bool Connect();
	void DisConnect();
	bool Listen();
	void Send(char* data);
};