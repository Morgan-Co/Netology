set(LAND_SOURCES
	Camel.cpp
	AllTerrainBoots.cpp
	Centaur.cpp
	SpeedsterCamel.cpp
	LandTransport.cpp
)

set(LAND_HEADERS
	Camel.h
	AllTerrainBoots.h
	Centaur.h
	SpeedsterCamel.h
	LandTransport.h
)

target_sources(RaceLib PRIVATE ${LAND_SOURCES} ${LAND_HEADERS})