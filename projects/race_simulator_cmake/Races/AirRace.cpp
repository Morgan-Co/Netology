#include "AirRace.h"
#include "../Enums/ERaceTypes.h"

AirRace::AirRace(int distance) : Race(distance) {
	type = ERaceTypes::air_race;
}