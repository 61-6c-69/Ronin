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
		char* request = "/";
	};

	//string to char
	static char* strTochr(string str){
		char *p = new char[strlen(str.c_str())];
		//strcpy(p, str.c_str());
		strcpy_s(p, strlen(p), str.c_str());
		return p;
	}
	
	//concat char
	static char* ConcatChr(char* a, char* b){
		size_t size = strlen(a) + strlen(b) + 1;
		char* c = new char[size];

		strcpy_s(c, size, a);
		strcat_s(c, size, b);

		return c;
	}

	//parse url
	static HURL ParseUrl(string url);

	//check is url
	static bool isUrl(char* url){
		if (Helper::ParseUrl(url).host != NULL){
			return true;
		}
		return false;
	}

	//check file exists
	static bool FileExists(char* path){
		ifstream ifs;

		ifs.open(path);
		bool ext = ifs.fail();
		ifs.close();

		return ext;
	}

	//string replace all
	static string ReplaceAll(string str, string find, string to){
		size_t pos = str.find(find);
		while (pos != string::npos){
			str.replace(pos, find.size(), to);
			pos = str.find(find, pos + to.size());
		}

		return str;
	}

	//translate string
	static string Translate(string str, map<string, string> mtemplate){
		for (auto t : mtemplate){
			str = Helper::ReplaceAll(str, t.first, t.second);
		}

		return str;
	}
};