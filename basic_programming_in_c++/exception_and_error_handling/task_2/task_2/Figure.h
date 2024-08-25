#pragma once
#include <string>
class Figure {
protected:
	std::string name;
	int sides_count = 0;
public:
	virtual void print_info() = 0;
	Figure();
};