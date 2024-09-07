#pragma once
#include "../Transport.h"

class AirTransport : public Transport {
protected:
	int distance_factor = 0;
public:
	AirTransport();
};