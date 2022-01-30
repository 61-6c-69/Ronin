#pragma once 
#include"Ronin.h"
#include"WinInet.h"

class HttpClient{
private:
	WinInet winet;
public:
	HttpClient(char* url){
		winet.setUrl(Helper::ParseUrl(url));
	}

	HttpClient& Post(){
		winet.setMethod(WinInet::REQUEST_METHOD::POST);
		return *this;
	}

	HttpClient& Get(){
		winet.setMethod(WinInet::REQUEST_METHOD::GET);
		return *this;
	}

	char* Result(char* data = NULL);
};