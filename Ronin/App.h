#pragma once
#include"Network.h"
#include"CommandMap.h"
#include"Hello.h"

class App{
public:
	static void Run(){
		Hello ho;
		CommandMap::Init().Add(&ho);

		if (Network::Init().Connect()){
			Network::Init().Listen();
		}
	}
};