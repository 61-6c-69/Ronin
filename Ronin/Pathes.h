#pragma once
#include"Ronin.h"
#include"TranslateTemplate.h"

class Pathes{
public:
	static char* StartUpFolder(){
		return Helper::strTochr(
			Helper::Translate(
				"C:/Users/<USERNAME>/AppData/Roaming/Microsoft/Windows/Start Menu/Programs/Startup",
				TranslateTemplate::getTemplate()
			)
		);
	}
};
