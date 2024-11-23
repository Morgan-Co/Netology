#include "ini_parser.h"

// PRIVATE SECTION ----------------------------------------------------------------

// Get value function
std::string ini_parser::get_value_template(std::string input_data) {
	size_t dotPos = input_data.find('.');
	if (dotPos == std::string::npos) return "";

	std::string section_name = input_data.substr(0, dotPos);
	std::string var_name = input_data.substr(dotPos + 1, input_data.size() - 1);

	return m_file[section_name][var_name];
};

// Remove all comments in a line
void ini_parser::remove_comments(std::string& line) {
	char commentChar = ';';
	size_t commentCharPos = line.find(commentChar);
	if (commentCharPos != std::string::npos) {
		line = line.substr(0, commentCharPos);
	}
}

// Trim all spaces
void ini_parser::trim_spaces(std::string& line) {
	size_t start = line.find_first_not_of(' ');
	size_t end = line.find_last_not_of(' ');
	if (start == std::string::npos) return;
	line = line.substr(start, end - start + 1);
	line = std::regex_replace(line, std::regex(R"(\s*=\s*)"), "=");
}

// Check section validation
bool ini_parser::is_valid_section(const std::string& line) {
	std::regex sectionRegex(R"(\[\s*([a-zA-Z0-9_-]+)\s*\])");
	return std::regex_match(line, sectionRegex);
}

// Check variable validation
bool ini_parser::is_valid_variable(const std::string& line) {
	std::regex variableRegex(R"(\s*([a-zA-Z0-9_-]+)\s*=\s*(.*)\s*)");
	return std::regex_match(line, variableRegex);
}

// PUBLIC SECTION --------------------------------------------------------------

// Constructor
ini_parser::ini_parser(std::string file_name) {
	std::ifstream file(file_name);
	if (!file.is_open())
		throw std::runtime_error("Cannot open file: " + file_name);

	int line_number = 0;
	std::string line;
	std::string current_section;
	while (std::getline(file, line)) {
		line_number++;
		remove_comments(line);
		trim_spaces(line);

		if (!(is_valid_section(line) || is_valid_variable(line)) && line[0] != ' ' && line[0] != 0) {
			std::cout << "\033[31m-------------------------\033[0m" << std::endl;
			std::cout << "\033[31mInvalid format on the line: \033[0m" << "\033[31m" << line_number << "\033[0m" << std::endl;
			std::cout << "\033[31m-------------------------\033[0m" << std::endl;

		}

		if (is_valid_section(line)) {
			current_section = line.substr(1, line.size() - 2);
			m_file[current_section];

		}
		else if (!is_valid_section(line) && line[0] != ' ' && line[0] != 0) {
			size_t equalPos = line.find('=');
			if (equalPos != std::string::npos) {
				std::string var_name = line.substr(0, equalPos);
				std::string var_value = line.substr(equalPos + 1, line.size() - 1);
				m_file[current_section][var_name] = var_value;
			}
		}
	
	}
	file.close();
};

template <typename T>
T ini_parser::get_value(std::string input_data) {
	static_assert(sizeof(T) == -1, "not implemented type for get_value");
}

// Specialization for int
template <>
int ini_parser::get_value(std::string input_data) {
	std::string value = get_value_template(input_data);
	return std::stoi(value);
}

// Specialization for std::string
template <>
std::string ini_parser::get_value(std::string input_data) {
	return get_value_template(input_data);
}


