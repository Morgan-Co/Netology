#pragma once

#include "../Transport.h"

class LandTransport : public Transport {
protected:
	int driving_time;
	int rest_duration;
	LandTransport() {
		type = land_race;
	}
};