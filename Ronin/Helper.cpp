#include"Helper.h"

Helper::HURL Helper::ParseUrl(string url){
	/*
	//
	//https://www.google.com:80/app?q=url-parser&page=1
	//
	// [0, find(://)] -> protocol, default(http)
	// [len(protocol), find(/ or : or end)] and remove(://) -> domain
	// [find(:), int] -> port, default (80)
	// [find(/), find(? or end)] -> path
	// [find(?), end] -> query
	*/

	Helper::HURL hurl;

	//protocol
	if (url.find("://") != string::npos){
		hurl.protocol = Helper::strTochr(url.substr(0, url.find("://")));
		url.erase(0, strlen(hurl.protocol) + 3);
	}

	//host
	if (url.find("/") || url.find(":") || url.find("?") || url.find("#")){
		hurl.host = Helper::strTochr(url.substr(0, url.find(":") ? url.find(":") : (url.find("/") ? url.find("/") : url.find("#"))));
		url.erase(0, strlen(hurl.host));
	}else{
		hurl.host = Helper::strTochr(url);
		return hurl;
	}
	
	//port
	if (url.find(":") != string::npos){
		hurl.port = stoi(url.substr(1, url.find("/") ? url.find("/") : url.length()-1));
		url.erase(0, url.find("/") ? url.find("/") : url.length() - 1);
	}
	
	//path
	if (url.length() > 0){
		hurl.path = Helper::strTochr(url.substr(0, url.find("?") ? url.find("?") : url.length()));

		//query
		if (url.find("?")){
			url.erase(0, url.find("?")+1);
			hurl.query = Helper::strTochr(url);
		}

		//hash
		if (url.find("#")){
			url.erase(0, url.find("#") + 1);
			hurl.hash = Helper::strTochr(url);
		}
	}

	return hurl;
}