#pragma once
#include"Ronin.h"
#include"TranslateTemplate.h"

class Pathes{
public:
	static char* StartUpFolder(){
		return Helper::strTochr(
			Helper::Translate(
				"<WINDRIVE>Users/<USERNAME>/AppData/Roaming/Microsoft/Windows/Start Menu/Programs/Startup",
				TranslateTemplate::getTemplate()
			)
		);
	}

	static char* StartUpRegistr() {
		return "HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\Run";
	}
};
