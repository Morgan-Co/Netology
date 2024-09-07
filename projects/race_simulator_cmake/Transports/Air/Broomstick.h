#pragma once
#include "AirTransport.h"

class Broomstick : public AirTransport {
public:
	Broomstick();
	double calculate_result(int distance) override;
};