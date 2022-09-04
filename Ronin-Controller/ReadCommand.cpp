#include"ReadCommand.h"

void ReadCommand::ParseCommand() {
	/*
		/ = command
		- = optinal
		space = next
		string = value for optional key
	*/
	this->command = "";

	for (int i = 0; i < this->command_string.length(); i++) {
		if (this->command_string[i] == ' ' && this->command != "") {
			break;
		}
		if (this->command_string[i] == '/') {
			this->command = '/';
			continue;
		}
		if (this->command != "") {
			this->command += this->command_string[i];
		}
	}

	bool is_key = false;
	CommandOption options;
	this->command_option.clear();
	int vector_item = -1;

	for (int i = 0;i < this->command_string.length();i++) {
		if (this->command_string[i] == '-') {
			this->command_option.push_back(options);
			is_key = true;
			options.key = "";
			options.value = "";
			vector_item++;
		}
		if (is_key && this->command_string[i] == ' ') {
			is_key = false;
		}
		if (is_key) {
			this->command_option[vector_item].key += this->command_string[i];
		}
		else if(vector_item>=0){
			if (this->command_option[vector_item].key != "") {
				this->command_option[vector_item].value += this->command_string[i];
			}
		}
	}
	
}

void ReadCommand::ReadLine() {
	std::getline(std::cin, this->command_string);
	this->ParseCommand();
}

std::string ReadCommand::getCommand() {
	return this->command;
}

bool ReadCommand::isKey(std::string key) {
	for each (CommandOption co in this->command_option)
	{
		if (co.key == key) {
			return true;
		}
	}
	return false;
}

ReadCommand::CommandOption ReadCommand::getOption(std::string key) {
	for each (CommandOption co in this->command_option)
	{
		if (co.key == key) {
			return co;
		}
	}
}