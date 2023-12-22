#include"LocationDetector.h"

bool LocationDetector::DetectByFlag(string your_flag) {
	return LOCATION_DETECTOR_COUNTRY == your_flag;
}

void LocationDetector::DetectOrClose(string your_flag) {
	if (LocationDetector::DetectByFlag(your_flag)) {
		Ronin::Log(1);
		exit(1);
	}
}