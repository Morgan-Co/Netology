#pragma once
#include "Race.h"

class MixedRace : public Race {
public:
	MixedRace(int ddistance) : Race(distance) {
		type = mixed_race;
	}
};