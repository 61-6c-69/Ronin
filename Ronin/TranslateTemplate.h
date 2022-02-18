#pragma once
#include"SystemInfo.h"

using namespace std;
class TranslateTemplate{
public:
	static map<string, string> getTemplate(){
		map<string, string> tt;

		tt.insert({ "<APPNAME>", APP_NAME });
		tt.insert({ "<COMPUTERNAME>", SystemInfo::ComputerName() });
		tt.insert({ "<EXEPATH>", SystemInfo::GetExecutablePath() });
		tt.insert({ "<WINDIR>", SystemInfo::GetWinDir() });
		tt.insert({ "<WINDRIVE>", SystemInfo::GetWinDrive() + "://" });
		tt.insert({ "<USERNAME>", SystemInfo::Username() });

		return tt;
	}
};