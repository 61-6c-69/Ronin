#include"HttpClient.h"

char* HttpClient::Result(char* data){
	if (!winet.OpenRequest()){
		return NULL;
	}
	return winet.SendRequest(data);
}