#pragma once
#include<iostream>
#include<map>
#include"Command.h"

class CommandMap{
private:
	std::map<string, Command*> cmd_map;
	static CommandMap* instance;

public:
	static CommandMap& Init(){
		if (!instance){
			instance = new CommandMap();
		}
		return *instance;
	}

	void Add(Command* cmd){
		cmd_map.insert({
			cmd[0].CommandName(),
			cmd 
		});
	}

	void Call(string cmd_name){
		cmd_map[cmd_name]->CommandCall();
	}
};

CommandMap *CommandMap::instance = 0;