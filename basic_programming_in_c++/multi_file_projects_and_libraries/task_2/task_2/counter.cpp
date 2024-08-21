#include "counter.h"
#include <iostream>

void Counter::set_initial_value(int initial_value) {
	value = initial_value;
}

void Counter::increase_value() {
	value++;
}

void Counter::decrease_value() {
	value--;
}

void Counter::show_value() {
	std::cout << value << std::endl;
}