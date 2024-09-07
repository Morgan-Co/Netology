#pragma once
#include <string>
#include <memory>

#include "../Enums/ERaceTypes.h"

class Transport {
protected:
	int id;
	double speed;
	std::string name = "Transport";

	ERaceTypes type = ERaceTypes::unknown;
public:
	bool operator==(const Transport& other) const;

	ERaceTypes& getType();
	const std::string& getName() const;
	const int getSpeed() const {
		return speed;
	}

	virtual ~Transport() = default;
	virtual double calculate_result(int distance) = 0;
};