#include "race_handler.h"

#include <iostream>

#include "../Races/LandRace.h"
#include "../Races/AirRace.h"
#include "../Races/MixedRace.h"

#include "../Functions/menus.h"
#include "../Functions/select_transport.h"
#include "../Functions/race_case.h"

void race_handler(const int& distance_length, int& action, const int& race_type, bool& isExit) {
	bool isStart = 1;
	bool isHaveTwoTransports = 0;
	Race* current_race = 0;
	bool isAnotherOne = 0;

	do {

		if (isStart)
		{
			if (!isHaveTwoTransports)
			{
				register_menu(action, false);
			}
			else {
				register_menu(action, true);
			}
		}
		isStart = 0;

		switch (action)
		{
		case 1: {

			do
			{
				int selected_option;
				switch (race_type)
				{
				case 1: {
					static LandRace land_race(distance_length);
					race_case(selected_option, land_race, isStart);
					current_race = &land_race;
					break;
				}
				case 2: {
					static AirRace air_race(distance_length);
					race_case(selected_option, air_race, isStart);
					current_race = &air_race;
					break;
				}
				case 3: {
					static MixedRace mixed_race(distance_length);
					race_case(selected_option, mixed_race, isStart);
					current_race = &mixed_race;
					break;
				}
				default:
					break;
				}
				if (isStart) break;
				if (current_race != nullptr && current_race->getTransports().size() >= 2) isHaveTwoTransports = 1;
				break;
			} while (true);
			break;
		}
		case 2: {
			if (current_race != nullptr && current_race->getTransports().size() < 2) break;
			int size;
			if (current_race != nullptr) size = current_race->getTransports().size();
			else break;


			std::cout << "Race results: " << std::endl;

			for (int i = 0; i < size; i++)
			{
				std::string name = current_race->getTransports()[i]->getName();
				double result = current_race->getTransports()[i]->calculate_result(distance_length);

				std::cout << (i + 1) << ". " << name << ". " << "Time (hours): " << result << std::endl;
			}
			std::cout << std::endl;

			int final_action = final_menu();
			if (final_action == 1) {
				isAnotherOne = 1;
				break;
			}
			else if (final_action == 2)
			{
				isExit = 1;
				break;
			}
			if (isAnotherOne) break;
		}
		default:
			break;
		}

		if (isAnotherOne || isExit) break;
	} while (true);
}