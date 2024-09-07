#include <algorithm>

#include "Race.h"
#include "../Enums/ERaceTypes.h"
#include "../Enums/EAddTransport.h"
#include "../Transports/Transport.h"

Race::Race(int distance) : distance(distance) {}

ERaceTypes Race::getType() {
	return type;
}


EAddTransport Race::add_transport(Transport* transport) {

	if (transport->getType() != type && type != mixed_race) {
		return EAddTransport::WrongType;
	}

	auto it = std::find_if(transports.begin(), transports.end(), [&](const Transport& t) {
		return t == *transport;
	});

	if (it == transports.end())
	{
		transports.push_back(*transport);
		return EAddTransport::Success;
	}
	else {
		return EAddTransport::AlreadyHas;
	}
}
