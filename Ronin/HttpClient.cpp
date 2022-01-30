#include"HttpClient.h"

char* HttpClient::Result(char* data = NULL){
	if (!winet.OpenRequest()){
		return NULL;
	}
	return winet.SendRequest(data);
}