#pragma once
#include<iostream>
#include<WinSock2.h>
#include<Windows.h>
#include<WinInet.h>
#include<string>
#include<vector>
#include<fstream>

#pragma comment(lib, "wininet.lib")
#pragma comment(lib, "Ws2_32.lib")


#include "Config.h"
#include"Log.h"
#include"Helper.h"

using namespace std;
class Ronin{
public:
	
	/*
	//method for log errors
	*/
	static void Log(int log){
		std::cout << "\nError: " << log << " -> " << ErrorLogs[log] << std::endl;
	}

	/*
	//method for install Ronin
	*/
	static void Install(){

	}
};