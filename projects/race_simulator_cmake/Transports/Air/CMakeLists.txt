set(AIR_SOURCES
    Broomstick.cpp
    MagicCarpet.cpp
    Eagle.cpp
    AirTransport.cpp
)

set(AIR_HEADERS
    Broomstick.h
    MagicCarpet.h
    Eagle.h
    AirTransport.h
)

target_sources(RaceLib PRIVATE ${AIR_SOURCES} ${AIR_HEADERS})
