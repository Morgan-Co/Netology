#pragma once
#include <vector>
#include "../Transports/Transport.h"

#include "../Enums/ERaceTypes.h"
#include "../Enums/EAddTransport.h"

class Race {
protected:
	int distance;
	ERaceTypes type;
	std::vector<Transport> transports;
public:
	Race(int distance);
	EAddTransport add_transport(Transport* transport);
	ERaceTypes getType();
};