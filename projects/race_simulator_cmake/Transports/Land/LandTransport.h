#pragma once

#include "../Transport.h"
#include <array>
#include <iostream>

class LandTransport : public Transport {
protected:
	double driving_time = 0;
	std::array<double, 3> rest_duration = {1.0, 1.0, 1.0};
public:
	LandTransport();
	double calculate_result(int distance) override;
};