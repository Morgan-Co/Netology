#include "MixedRace.h"
#include "Race.h"
#include "../Enums/ERaceTypes.h"

MixedRace::MixedRace(int distance) : Race(distance) {
	type = ERaceTypes::mixed_race;
}