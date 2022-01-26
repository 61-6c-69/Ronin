#pragma once
#include"Ronin.h"

using namespace std;
class Helper{
public:
	struct HAObject{
		char* key;
		char* value;
	};

	struct HURL{
		char* protocol;
		char* host;
		int port = 80;
		char* path = "/";
		char* query;
		char* hash;
	};

	//string to char
	static char* strTochr(string str){
		char *p = new char[strlen(str.c_str())];
		//strcpy(p, str.c_str());
		strcpy_s(p, strlen(p), str.c_str());
		return p;
	}

	//parse url
	static HURL ParseUrl(string url);

	//check file exists
	static bool FileExists(char* path){
		ifstream ifs;

		ifs.open(path);
		bool ext = ifs.fail();
		ifs.close();

		return ext;
	}
};