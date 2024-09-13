#pragma once
#include <vector>
#include <algorithm>
#include "../Transports/Transport.h"

void transports_menu(const std::vector<std::unique_ptr<Transport>> &transports);

const int select_race_menu();

const int specify_distance_menu();

void register_menu(int& action, bool extended_menu = 0);

const int final_menu();