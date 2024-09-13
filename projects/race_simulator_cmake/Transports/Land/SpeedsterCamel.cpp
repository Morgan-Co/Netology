#include "SpeedsterCamel.h"

SpeedsterCamel::SpeedsterCamel() {
	id = 6;
	speed = 40;
	type = land_race;
	name = "Camel-Speedster";

	driving_time = 10;
	rest_duration = {5.0, 6.5, 8.0};
}

double SpeedsterCamel::calculate_result(int distance) {
		double time_without_stops = distance / speed;
		double stops_count = std::ceil((distance / (speed * driving_time))) - 3;
		double stops_time = rest_duration[0] + rest_duration[1] + (stops_count * rest_duration[2]);
		double result = time_without_stops + stops_time;
		return result;
}