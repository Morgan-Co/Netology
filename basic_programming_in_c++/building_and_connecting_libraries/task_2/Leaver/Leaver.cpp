#include <string>
#include <iostream>
#include "Leaver.h"

namespace Leaver {
	void Leaver::leave(std::string name) {
		std::cout << "Goodbye, " << name << '!' << std::endl;
	}
}