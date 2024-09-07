#pragma once
#include "AirTransport.h"

class Eagle : public AirTransport {
public:
	Eagle() {
		id = 5;
		speed = 8;
		name = "Eagle";

		distance_factor = 6;
	}
};