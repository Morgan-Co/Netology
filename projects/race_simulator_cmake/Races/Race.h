#pragma once
#include <vector>
#include <memory>
#include "../Transports/Transport.h"

#include "../Enums/ERaceTypes.h"
#include "../Enums/EAddTransport.h"

class Race {
protected:
	int distance;
	ERaceTypes type = ERaceTypes::unknown;
	std::vector<std::unique_ptr<Transport>> transports;
public:
	Race(int distance);

	ERaceTypes& getType();

	const EAddTransportCode add_transport(std::unique_ptr<Transport> transport);

	const std::vector<std::unique_ptr<Transport>>& getTransports() const;

	const int& getDistance() const;

	void clear_transports();

};