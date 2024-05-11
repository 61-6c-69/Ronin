#pragma once

class Command{
public:
	//command name
	virtual string CommandName() const = 0;

	//call command
	virtual void  CommandCall(string) const = 0;

protected:
	//response template
	struct Response {
		bool status;
		char* command;
		char* body;

		char* toChar() {
			json::JSON jj;

			jj["status"] = status;
			jj["command"] = command;
			jj["result"] = body;

			return Helper::strTochr(jj.dump());
		}
	};
};