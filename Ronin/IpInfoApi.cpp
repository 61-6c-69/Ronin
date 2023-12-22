#include"IpInfoApi.h"

IpInfoApi::IPINFO_API_RESULT IpInfoApi::getResult() {
	char* data = HttpClient("http://ip-api.com/json/").Get().Result();

	json::JSON obj = json::JSON::Load(data);

	IpInfoApi::IPINFO_API_RESULT iar;

	try
	{
		iar.status = obj["status"].ToString();
		iar.code = obj["countryCode"].ToString();
		iar.country = obj["country"].ToString();
		iar.region = obj["region"].ToString();
		iar.regionName = obj["regionName"].ToString();
		iar.city = obj["city"].ToString();
		iar.zip = obj["zip"].ToString();
		iar.lat = obj["lat"].ToString();
		iar.lon = obj["lon"].ToString();
		iar.timezone = obj["timezone"].ToString();
		iar.isp = obj["isp"].ToString();
		iar.org = obj["org"].ToString();
		iar.as = obj["as"].ToString();
		iar.query = obj["query"].ToString();
	}
	catch(...){

	}

	return iar;
}