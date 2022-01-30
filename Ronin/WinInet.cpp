#include"WinInet.h"

bool WinInet::OpenRequest(){
	this->hopen = InternetOpen(APP_NAME, INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);

	if (this->url.host == NULL){
		return false;
	}

	if (!this->hopen){
		return false;
	}

	this->hconnect = InternetConnect(
		this->hopen, 
		this->url.host, 
		this->url.port, 
		NULL, 
		NULL, 
		INTERNET_SERVICE_HTTP, 
		0, 
		0
	);
	if (!this->hconnect){
		return false;
	}

	this->hrequest = HttpOpenRequest(
		this->hconnect,
		(this->method == WinInet::REQUEST_METHOD::GET ? "GET" : "POST") ,
		Helper::ConcatChr(this->url.path, this->url.query),
		"HTTP/1.1",
		NULL,
		NULL,
		(this->url.protocol == "https" ? INTERNET_FLAG_SECURE : NULL),
		0
	);
	if (!this->hrequest){
		return false;
	}

	return true;
}

char* WinInet::SendRequest(char* data){
	string data_str;
	char buf[1024];
	DWORD data_avilable, data_read;

	if (!HttpSendRequest(
		this->hrequest,
		NULL,
		0,
		data,
		(data == NULL ? 0 : strlen(data))
		)
	){
		return "";
	}

	while(InternetQueryDataAvailable(this->hrequest, &data_avilable, 0, 0) && data_avilable != 0){
		if (InternetReadFile(this->hrequest, buf, sizeof(buf), &data_read)){
			if (data_read == 0){
				return Helper::strTochr(data_str);
			}
			data_str.append(buf, data_read);
		}
	}
	
	return Helper::strTochr(data_str);
}

void WinInet::Close(){
	InternetCloseHandle(this->hrequest);
	InternetCloseHandle(this->hconnect);
	InternetCloseHandle(this->hopen);
}