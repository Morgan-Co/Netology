#include "Eagle.h"

Eagle::Eagle() {
	id = 5;
	speed = 8;
	name = "Eagle";

	distance_factor = 0.06;
}

double Eagle::calculate_result(int distance) {
	double distance_with_shortening = distance * (1 - distance_factor);
	double result = distance_with_shortening / speed;
	return result;
}