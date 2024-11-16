#include <fstream>
#include <string>
#include <iostream>
#include <stdexcept>
#include "ini_parser/ini_parser.h"


int main() {
	ini_parser parser("../../../some.ini");
	//parser.print_file();
	auto value = parser.get_value("Section1.value");
	std::cout << value << std::endl;
}