#pragma once
#include"Ronin.h"

class LocationDetector
{
public:
	static bool EnableLocationDetect() {
		return LOCATION_DETECTOR;
	}

	//just run on this flag
	static bool DetectByFlag(string your_flag);

	//close app
	static void DetectOrClose(string your_flag);
};

