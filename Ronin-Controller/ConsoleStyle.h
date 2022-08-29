#include<iostream>
#include<Windows.h>

class ConsoleStyle {
public:
	enum CONSOLE_TEXT_COLORS {
		TEXT_BLUE      = FOREGROUND_BLUE,
		TEXT_GREEN     = FOREGROUND_GREEN,
		TEXT_INTENSITY = FOREGROUND_INTENSITY,
		TEXT_RED       = FOREGROUND_RED
	};

	static void setConsoleTextColor(HANDLE console, CONSOLE_TEXT_COLORS cc) {
		SetConsoleTextAttribute(console, cc);
	}

	static void setConsoleText(char* s) {
		SetConsoleTitle(s);
	}
};