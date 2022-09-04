#include<iostream>
#include"Config.h"
#include"SysStrings.h"
#include"Helper.h"
#include"ReadCommand.h"

using namespace std;

int main(){
	/*
	*write app name
	*/
	cout << APP_NAME << "(" << APP_VERSION << ")" << endl << endl;

	/*
	*set console color
	*/
	ConsoleStyle::setConsoleTextColor(
		Helper::getSTDOutputHandle(),
		CONSOLE_TEXT_COLOR
	);

	/*
	*set console title
	*/
	ConsoleStyle::setConsoleText(APP_NAME);

	/*
	*commands
	*/
	for(int i = 0; i < commands_array.size(); i++){
		cout << commands_array[i] <<endl;
	}
}