#include <iostream>
#include <vector>
#include <string>

#include "Transports/Transport.h"
#include "Transports/Land/Camel.h"
#include "Transports/Land/AllTerrainBoots.h"
#include "Transports/Land/SpeedsterCamel.h"
#include "Transports/Land/Centaur.h"
#include "Transports/Air/Broomstick.h"
#include "Transports/Air/MagicCarpet.h"
#include "Transports/Air/Eagle.h"

//#include "Races/Race.h"
#include "Races/LandRace.h"
#include "Races/AirRace.h"
#include "Races/MixedRace.h"

#include "Enums/ERaceTypes.h"
#include "Enums/ETransports.h"
#include "Enums/EAddTransport.h"


void print_menu();



void add_transport_handler(EAddTransport code, Transport* t) {
	if (code == EAddTransport::Success)
	{
		std::cout << t->getName() << " has been successfully registered" << std::endl;
	}
	else if (code == EAddTransport::AlreadyHas) {
		std::cout << t->getName() << " has already been registered!" << std::endl;
	}
	else if (code == EAddTransport::WrongType) {
		std::cout << "Attempt to register the wrong type of transport!" << std::endl;
	}
}




void select_transport(ETransports transport, Race& race) {
	switch (transport)
	{
	case boots: {
		add_transport_handler(race.add_transport(new AllTerrainBoots), new AllTerrainBoots);
		break;
	}
	case broomstick: {
		add_transport_handler(race.add_transport(new Broomstick), new Broomstick);
		break;
	}
	case camel: {
		add_transport_handler(race.add_transport(new Camel), new Camel);
		break;
	}
	case centaur: {
		add_transport_handler(race.add_transport(new Centaur), new Centaur);
		break;
	}
	case eagle: {
		add_transport_handler(race.add_transport(new Eagle), new Eagle);
		break;
	}
	case speedster_camel: {
		add_transport_handler(race.add_transport(new SpeedsterCamel), new SpeedsterCamel);
		break;
	}
	case magic_carpet: {
		add_transport_handler(race.add_transport(new MagicCarpet), new MagicCarpet);
		break;
	}
	case 0: {

	}
	default:
		break;
	}
}


void register_menu(int& action) {
	std::cout << "At least two transports must be registered" << std::endl;
	std::cout << "1. Register a transport" << std::endl;
	std::cout << "Select an action: ";
	std::cin >> action;
	std::cout << std::endl;
}

void register_menu(int action, int t_count) {
	std::cout << "At least two transports must be registered" << std::endl;
	std::cout << "1. Register a transport" << std::endl;
	std::cout << "Select an action: ";
	std::cin >> action;
	std::cout << std::endl;
}




int main() {
	int race_type;
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

	int distante_length;
	std::cout << "Specify the length of the distance: ";
	std::cin >> distante_length;
	std::cout << std::endl;

	int action;
	do
	{
		register_menu(action);

	} while (action != 1);
	
	do
	{
		int selected_option;
		switch (race_type)
		{
		case 1: {
			static LandRace land_race(distante_length);
			std::cout << "Race for the land transport. Distance: " << distante_length << std::endl;
			print_menu();
			std::cin >> selected_option;
			std::cout << std::endl;
			select_transport(static_cast<ETransports>(selected_option), land_race);
			break;
		}
		case 2: {
			static AirRace air_race(distante_length);
			std::cout << "Race for the air transport. Distance: " << distante_length << std::endl;
			print_menu();
			std::cin >> selected_option;
			select_transport(static_cast<ETransports>(selected_option), air_race);
			break;
		}
		case 3: {
			static MixedRace mixed_race(distante_length);
			std::cout << "Race for the land and air transport. Distance: " << distante_length << std::endl;
			print_menu();
			std::cin >> selected_option;
			select_transport(static_cast<ETransports>(selected_option), mixed_race);
			break;
		}
		default:
			break;
		}
	} while (true);

}

void print_menu() {
	std::cout << "1. All Terrain Boots" << std::endl;
	std::cout << "2. Broomstick" << std::endl;
	std::cout << "3. Camel" << std::endl;
	std::cout << "4. Centaur" << std::endl;
	std::cout << "5. Eagle" << std::endl;
	std::cout << "6. Camel-Speedster" << std::endl;
	std::cout << "7. Magic Carpet" << std::endl;
	std::cout << "0. Finish Registration" << std::endl;
}


