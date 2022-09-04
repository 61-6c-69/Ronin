#include<iostream>
#include<string>
#include<vector>

#define COMMAND_LINE_LENGTH 256

class ReadCommand {
	struct CommandOption {
		std::string key;
		std::string value;
	};
private:
	std::string command_string;
	
	std::string command; // exm: /info
	std::vector<CommandOption> command_option; //vector of coomands options

	void ParseCommand();
public:
	void ReadLine();
	std::string getCommand();
	bool isKey(std::string key);
	CommandOption getOption(std::string key);
};