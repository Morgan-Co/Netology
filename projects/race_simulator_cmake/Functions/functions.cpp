#include <iostream>
#include "functions.h"
#include "../Enums/ETransports.h"
#include "../Races/Race.h"

void print_menu() {
	std::cout << "1. All Terrain Boots" << std::endl;
	std::cout << "2. Broomstick" << std::endl;
	std::cout << "3. Camel" << std::endl;
	std::cout << "4. Centaur" << std::endl;
	std::cout << "5. Eagle" << std::endl;
	std::cout << "6. Camel-Speedster" << std::endl;
	std::cout << "7. Magic Carpet" << std::endl;
	std::cout << "0. Finish Registration" << std::endl;
	std::cout << "Select transport or 0 to end registration: ";
}

void select_race(int& race_type) {
	do
	{
		std::cout << "Welcome to the racing simulator!" << std::endl;
		std::cout << "1. The first race for a land transport" << std::endl;
		std::cout << "2. The second air transport race" << std::endl;
		std::cout << "3. The third race for a land and air transport" << std::endl;
		std::cout << "Choose the type of race: ";
		std::cin >> race_type;
		std::cout << std::endl;
		if (race_type == 1 || race_type == 2 || race_type == 3) break;
	} while (true);
}

void specify_distance(int& distance_length) {
	std::cout << "Specify the length of the distance: ";
	std::cin >> distance_length;
	std::cout << std::endl;
}

void register_menu(int& action, bool extended_menu) {
	if (!extended_menu)
	{
		std::cout << "At least two transports must be registered" << std::endl;
		std::cout << "1. Register a transport" << std::endl;
		std::cout << "Select an action: ";
		std::cin >> action;
		std::cout << std::endl;
		return;
	}

	std::cout << "At least two transports must be registered" << std::endl;
	std::cout << "1. Register a transport" << std::endl;
	std::cout << "2. Start the race" << std::endl;
	std::cout << "Select an action: ";
	std::cin >> action;
	std::cout << std::endl;
}

