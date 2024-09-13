#pragma once
#include "LandTransport.h"

class SpeedsterCamel : public LandTransport {
public:
	SpeedsterCamel();
	double calculate_result(int distance) override;
};