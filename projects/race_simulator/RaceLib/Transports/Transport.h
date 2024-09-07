#pragma once
#ifdef RACELIB_EXPORTS
#define RACELIB_API __declspec(dllimport)
#else
#define RACE_API __declspec(dllexport)
#endif // RACELIB_EXPORTS

#include <string>

#include "../Enums/ERaceTypes.h"

class Transport {
protected:
	int id;
	int speed;
	ERaceTypes type;
	std::string name;
public:
	ERaceTypes getType();
	std::string getName();
	bool operator==(const Transport &other) const;
};
