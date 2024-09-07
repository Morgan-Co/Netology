#include "Broomstick.h"
#include <iostream>

Broomstick::Broomstick() {
	id = 2;
	name = "Broomstick";
	speed = 20;

	distance_factor = 0.01;
}

double Broomstick::calculate_result(int distance) {
	distance_factor *= std::floor(distance / 1000);
	std::cout << distance_factor << std::endl;
	double distance_with_shortening = distance * (1 - distance_factor);
	double result = distance_with_shortening / speed;
	return result;
}