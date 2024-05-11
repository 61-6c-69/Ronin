#pragma once
#include"SysFile.h"

class FileHelper {
public:
	static bool CopyTo(char* src, char* to);
	static void CreateDir(char* src);
};