#include <fstream>
#include <string>
#include <iostream>
#include <stdexcept>
#include "ini_parser/ini_parser.h"

int main() {
	ini_parser parser("../../../some.ini");
	
	auto value = parser.get_value<int>("Section1.value");
	std::cout << value << std::endl;
}