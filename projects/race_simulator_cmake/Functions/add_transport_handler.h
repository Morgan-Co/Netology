#pragma once
#include "../Enums/EAddTransport.h"
#include "../Transports/Transport.h"
#include <memory>

void add_transport_handler(EAddTransportCode code, std::string name);