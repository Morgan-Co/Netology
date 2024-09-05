#include "Leaver.h"
#include <string>
#include <iostream>

namespace Leaver {
	void Leaver::leave(std::string name) {
		std::cout << "Goodbye, " << name << '!' << std::endl;
	}
}