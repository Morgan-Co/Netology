#pragma once
#include <string>
#include <stdexcept>

class InvalidFigure : public std::domain_error {
public:
	explicit InvalidFigure(const std::string& message) : std::domain_error(message) {};
};