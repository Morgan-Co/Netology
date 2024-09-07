#include "Transport.h"
#include "../Enums/ERaceTypes.h"
#include <memory>

bool Transport::operator==(const Transport& other) const {
	return id == other.id;
}

ERaceTypes& Transport::getType() {
	return type;
}

const std::string& Transport::getName() const {
	return name;
}