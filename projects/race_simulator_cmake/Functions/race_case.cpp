#include "race_case.h"
#include <iostream>

#include "../Functions/menus.h"
#include "../Functions/select_transport.h"

void race_case(int& selected_option, Race& race, bool& isStart) {
	std::cout << "Race for the land transport. Distance: " << race.getDistance() << std::endl;
	transports_menu();
	std::cin >> selected_option;
	std::cout << std::endl;
	select_transport(static_cast<ETransports>(selected_option), race, isStart);
};