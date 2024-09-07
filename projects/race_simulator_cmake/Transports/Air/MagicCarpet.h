#pragma once
#include "AirTransport.h"
#include <iostream>

class MagicCarpet : public AirTransport {
public:
	MagicCarpet();
	double calculate_result(int distance) override;
};