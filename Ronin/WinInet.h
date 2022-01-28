#pragma once
#include"Ronin.h"

class WinInet{
public:
	enum REQUEST_METHOD{
		GET,
		POST
	};
private:
	Helper::HURL url;
	REQUEST_METHOD method;
	HINTERNET hopen;
	HINTERNET hconnect;
	HINTERNET hrequest;

public:
	void setUrl(Helper::HURL url){
		this->url = url;
	}

	void setMethod(REQUEST_METHOD rm){
		this->method = rm;
	}

	bool OpenRequest();
	char* SendRequest(char* data = NULL);
	void Close();

	~WinInet(){
		this->Close();
	}
};