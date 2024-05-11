#pragma once
#include"Ronin.h"

class Keyboard {
private:
	char log_size[KEYBOARD_LOG_SIZE];

public:
	void Start(void(*callback)(char*));
	void Stop();
};