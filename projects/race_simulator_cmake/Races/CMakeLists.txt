set(RACES_SOURCES
	Race.cpp
	AirRace.cpp
	LandRace.cpp
	MixedRace.cpp
)

set(RACES_HEADERS
	Race.h
	AirRace.h
	LandRace.h
	MixedRace.h
)

target_sources(RaceLib PRIVATE ${RACES_SOURCES} ${RACES_HEADERS})