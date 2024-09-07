#include "select_transport.h"
#include "../Enums/ETransports.h"
#include "../Races/Race.h"
#include "add_transport_handler.h"

#include "../Transports/Transport.h"
#include "../Transports/Land/Camel.h"
#include "../Transports/Land/AllTerrainBoots.h"
#include "../Transports/Land/SpeedsterCamel.h"
#include "../Transports/Land/Centaur.h"
#include "../Transports/Air/Broomstick.h"
#include "../Transports/Air/MagicCarpet.h"
#include "../Transports/Air/Eagle.h"

#include <iostream>
#include <memory>

void select_transport(ETransports transport, Race& race, bool& isStart) {
	switch (transport)
	{
	case boots: {
		std::unique_ptr<AllTerrainBoots> boots_ = std::make_unique<AllTerrainBoots>();
		std::string name = boots_->getName();
		EAddTransportCode code = race.add_transport(std::move(boots_));
		add_transport_handler(code, name);
		break;
	}
	case broomstick: {
		std::unique_ptr<Broomstick> broomstick_ = std::make_unique<Broomstick>();
		std::string name = broomstick_->getName();
		EAddTransportCode code = race.add_transport(std::move(broomstick_));
		add_transport_handler(code, name);
		break;
	}
	case camel: {
		std::unique_ptr<Camel> camel_ = std::make_unique <Camel>();
		std::string name = camel_->getName();
		EAddTransportCode code = race.add_transport(std::move(camel_));
		add_transport_handler(code, name);
		break;
	}
	case centaur: {
		std::unique_ptr<Centaur> centaur_ = std::make_unique <Centaur>();
		std::string name = centaur_->getName();
		EAddTransportCode code = race.add_transport(std::move(centaur_));
		add_transport_handler(code, name);
		break;
	}
	case eagle: {
		std::unique_ptr<Eagle> eagle_ = std::make_unique <Eagle>();
		std::string name = eagle_->getName();
		EAddTransportCode code = race.add_transport(std::move(eagle_));
		add_transport_handler(code, name);
		break;
	}
	case speedster_camel: {
		std::unique_ptr<SpeedsterCamel> speedster_camel_ = std::make_unique <SpeedsterCamel>();
		std::string name = speedster_camel_->getName();
		EAddTransportCode code = race.add_transport(std::move(speedster_camel_));
		add_transport_handler(code, name);
		break;
	}
	case magic_carpet: {
		std::unique_ptr<MagicCarpet> magic_carpet_ = std::make_unique <MagicCarpet>();
		std::string name = magic_carpet_->getName();;
		EAddTransportCode code = race.add_transport(std::move(magic_carpet_));
		add_transport_handler(code, name);
		break;
	}
	case 0: {
		isStart = 1;
		break;
	}
	default:
		break;
	}

}