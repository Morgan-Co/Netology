#pragma once
#include <string>

#include "../Enums/ERaceTypes.h"

class Transport {
protected:
	int id;
	int speed;
	std::string name;

	ERaceTypes type;
public:
	ERaceTypes getType();
	std::string getName();
	bool operator==(const Transport &other) const;
};
