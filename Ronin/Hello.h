
#include<iostream>
#include"Command.h"

class Hello: public Command{
public:
	string CommandName() const override{
		return "Hello";
	}

	void CommandCall(string data) const override{
		std::cout << "Hello World ;)" << endl;

		if (data.length()>0){
			cout <<"data: " << data << endl;
		}
	}
};