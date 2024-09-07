#include "MagicCarpet.h"

MagicCarpet::MagicCarpet() {
	id = 7;
	name = "Magic Carpet";
	speed = 10;
}

double MagicCarpet::calculate_result(int distance) {
	if (distance < 1000) distance_factor = 1;
	else if (distance < 5000) distance_factor = 0.03;
	else if (distance < 10000) distance_factor = 0.1;
	else if (distance >= 10000) distance_factor = 0.05;

	double distance_with_shortening = distance * (1 - distance_factor);
	double result = distance_with_shortening / speed;
	return result;
}