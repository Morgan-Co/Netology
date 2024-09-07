#include "LandTransport.h"

LandTransport::LandTransport() {
	type = ERaceTypes::land_race;
}
double LandTransport::calculate_result(int distance) {
	double time_without_stops = distance / speed;
	double stops_count = std::ceil((distance / (speed * driving_time))) - 2;
	double stops_time = rest_duration[0] + (stops_count * rest_duration[1]);
	double result = time_without_stops + stops_time;
	return result;
}