#include <string>
#include "Greeter.h"

namespace Greeter {
	void Greeter::greet(std::string name) {
		std::cout << "Hello, " << name << '!' << std::endl;
	};
}