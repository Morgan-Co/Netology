#include "Transport.h"
#include "../Enums/ERaceTypes.h"

bool Transport::operator==(const Transport& other) const {
	return id == other.id;
}

ERaceTypes Transport::getType() {
	return type;
}

std::string Transport::getName() {
	return name;
}