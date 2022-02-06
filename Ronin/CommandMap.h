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
		if (cmd_map.count(cmd[0].CommandName())){
			cout << "no1";
			return;
		}

		cmd_map.insert({
			cmd[0].CommandName(),
			cmd 
		});
	}

	void Call(string cmd_name, string data){
		if (!cmd_map.count(Helper::strTochr(cmd_name.c_str()))){
			cout << "no2";
			return;
		}

		cmd_map[cmd_name]->CommandCall(data);
	}
};

CommandMap *CommandMap::instance = 0;