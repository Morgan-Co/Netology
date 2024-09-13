set(FUNCTIONS_SOURCES
    race_case.cpp
    menus.cpp
    select_transport.cpp
    add_transport_handler.cpp
    race_handler.cpp
)

set(FUNCTIONS_HEADERS
    race_case.h
    menus.h
    select_transport.h
    add_transport_handler.h
    race_handler.h
)

target_sources(RaceLib PRIVATE ${FUNCTIONS_SOURCES} ${FUNCTIONS_HEADERS})
