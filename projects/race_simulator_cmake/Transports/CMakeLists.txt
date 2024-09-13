add_subdirectory(Land)
add_subdirectory(Air)

set(TRANSPORT_SOURCES 
	Transport.cpp
)

set(TRANSPORTS_HEADERS
    Transport.h
)

target_sources(RaceLib PRIVATE ${TRANSPORT_SOURCES} ${TRANSPORTS_HEADERS})