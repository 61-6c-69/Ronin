
#pragma once
#include"Command.h"

class Hello: public Command{
public:
	string CommandName() const override{
		return "Hello";
	}

	void CommandCall(string data) const override{
		if (data.length()>0){
			cout <<"data: " << data << endl;
		}

		
		Response response;

		response.status = true;
		response.command = Helper::strTochr(CommandName());
		response.body = "Hello Server";
		
		Network::Init().Send(response.toChar());
	}
};