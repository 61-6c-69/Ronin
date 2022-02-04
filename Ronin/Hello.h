
#include<iostream>
#include"Command.h"

class Hello: public Command{
public:
	string CommandName() const override{
		return "Hello";
	}

	void CommandCall() const override{
		std::cout << "Hello World ;)";
	}
};