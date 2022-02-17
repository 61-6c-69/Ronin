#pragma once
#include"Ronin.h"
class SystemInfo{
public:
	static char* ComputerName();
	static char* GetExecutablePath();
	static char* GetWinDir();
	static char GetWinDrive();
	static char* Username();
};