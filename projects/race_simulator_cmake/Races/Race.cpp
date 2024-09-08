#include <algorithm>
#include <vector>

#include "Race.h"
#include "../Enums/ERaceTypes.h"
#include "../Enums/EAddTransport.h"
#include "../Transports/Transport.h"

Race::Race(int distance) : distance(distance) {}

ERaceTypes& Race::getType() {
	return type;
}

const std::vector<std::unique_ptr<Transport>>& Race::getTransports() {
	return transports;
};


const EAddTransportCode Race::add_transport(std::unique_ptr<Transport> transport) {

	if (transport->getType() != type && type != mixed_race) {
		return EAddTransportCode::WrongType;
	}

	auto it = std::find_if(transports.begin(), transports.end(), [&](const std::unique_ptr<Transport>& t) {
		return *t == *transport;
	});

	if (it == transports.end())
	{
		transports.push_back(std::move(transport));
		return EAddTransportCode::Success;
	}
	else {
		return EAddTransportCode::AlreadyHas;
	}
}

const int& Race::getDistance() const {
	return distance;
}