#pragma once
#include "AirTransport.h"
#include <iostream>

class Eagle : public AirTransport {
public:
	Eagle();
	double calculate_result(int distance) override;
};