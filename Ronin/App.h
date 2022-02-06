#pragma once
#include"Network.h"
#include"CommandMap.h"
#include"Hello.h"

class App{
public:
	static void Run(){
		//use class
		Hello ho;
		CommandMap::Init().Add(&ho);

		//connect and listen on server
		if (Network::Init().Connect()){
			Network::Init().Listen();
		}
	}
};