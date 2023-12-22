#pragma once
//
// class for ip-api.com
// api location ip-api.com/json/
//

#include"HttpClient.h"
#include"json.h"

class IpInfoApi
{
public:
	struct IPINFO_API_RESULT
	{
		string status;
		string country;
		string code;
		string region;
		string regionName;
		string city;
		string zip;
		string lat;
		string lon;
		string timezone;
		string isp;
		string org;
		string as;
		string query;
	};
	static IPINFO_API_RESULT getResult();
};

