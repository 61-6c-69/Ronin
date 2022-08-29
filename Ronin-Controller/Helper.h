#include<iostream>
#include<Windows.h>

class Helper {
public:
	static HANDLE getSTDOutputHandle() {
		return GetStdHandle(STD_OUTPUT_HANDLE);
	}
};