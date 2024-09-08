#include <iostream>
#include <vector>
#include <string>

#include "Functions/select_transport.h"

#include "Races/LandRace.h"
#include "Races/AirRace.h"
#include "Races/MixedRace.h"

#include "Enums/ERaceTypes.h"
#include "Enums/ETransports.h"
#include "Enums/EAddTransport.h"

#include "Functions/menus.h"
#include "Functions/race_handler.h"




int main() {
	int action;
	int race_type;
	int distance_length;
	bool isExit = 0;
	do
	{
		race_type = select_race_menu();
		distance_length = specify_distance_menu();
		race_handler(distance_length, action, race_type, isExit);

		if (isExit) break;
	} while (true);

}



