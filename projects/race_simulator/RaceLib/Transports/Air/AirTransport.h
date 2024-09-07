#pragma once
#include "../Transport.h"

class AirTransport : public Transport {
protected:
	int distance_factor;
public:
	AirTransport() {
		type = air_race;
	}
};