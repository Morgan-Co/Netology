#include "add_transport_handler.h"
#include <iostream>

void add_transport_handler(EAddTransportCode code, std::string name) {
	if (code == EAddTransportCode::Success)
	{
		std::cout << name << " has been successfully registered" << std::endl;
	}
	else if (code == EAddTransportCode::AlreadyHas) {
		std::cout << name << " has already been registered!" << std::endl;
	}
	else if (code == EAddTransportCode::WrongType) {
		std::cout << "Attempt to register the wrong type of transport!" << std::endl;
	}
}