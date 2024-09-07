#include "LandRace.h"
#include "../Enums/ERaceTypes.h"

LandRace::LandRace(int distance) : Race(distance) {
	type = ERaceTypes::land_race;
}