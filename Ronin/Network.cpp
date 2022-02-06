#include"Network.h"

bool Network::Connect(){
	if (this->socket.Connect()){
		return true;
	}
	return false;
}

void Network::DisConnect(){
	if (this->socket.isConnect()){
		this->socket.Close();
	}
}

void ListenSocket(char* data){
	try{
		json::JSON obj = json::JSON::Load(data);
		CommandMap::Init().Call(obj["command"].ToString(), obj["body"].ToString());
	}
	catch (exception e){
		cout << "json parse error";
	}
}

bool Network::Listen(){
	if (this->socket.isConnect()){
		this->socket.Recv(ListenSocket);
		return true;
	}
	return false;
}