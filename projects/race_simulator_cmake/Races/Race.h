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
	const EAddTransportCode add_transport(std::unique_ptr<Transport> transport);
	ERaceTypes& getType();
	const std::vector<std::unique_ptr<Transport>>& getTransports();



};