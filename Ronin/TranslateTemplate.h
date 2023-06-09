#pragma once
#include"SystemInfo.h"

using namespace std;
class TranslateTemplate{
public:
	static map<string, string> getTemplate(){
		map<string, string> tt;

		char windrive[] = { SystemInfo::GetWinDrive(), ':', '/', '/', '\0' };

		tt.insert({ "<APPNAME>", APP_NAME });
		tt.insert({ "<COMPUTERNAME>", SystemInfo::ComputerName() });
		tt.insert({ "<EXEPATH>", SystemInfo::GetExecutablePath() });
		tt.insert({ "<WINDIR>", SystemInfo::GetWinDir() });
		tt.insert({ "<WINDRIVE>", windrive });
		tt.insert({ "<USERNAME>", SystemInfo::Username() });

		return tt;
	}
};