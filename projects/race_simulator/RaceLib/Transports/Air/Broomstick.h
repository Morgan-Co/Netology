#pragma once
#include "AirTransport.h"

class Broomstick : public AirTransport {
public:
	Broomstick() {
		id = 2;
		speed = 20;
	}
};