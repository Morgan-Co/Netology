#include "ini_parser.h"

// PRIVATE SECTION ----------------------------------------------------------------

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
	m_file = std::move(file);
	file.close();
};

// Get value function
std::string ini_parser::get_value(std::string input_data) {
	std::string section_name, var_name;
	int line_number = 0;

	size_t dot_position = input_data.find(".");

	if (dot_position != std::string::npos)
	{
		section_name = "[" + input_data.substr(0, dot_position) + "]";
		var_name = input_data.substr(dot_position + 1, input_data.size() - 1);
	}
	std::string line;
	bool inSection = false;
	std::string finish_value;
	size_t i = 0;
	std::vector<std::pair<std::string, std::string>> section_vars;
	while (std::getline(m_file, line)) {
		line_number++;
		remove_comments(line);
		trim_spaces(line);
		if (!(is_valid_section(line) || is_valid_variable(line)) && line[0] != ' ' && line[0] != 0) {
			std::cout << "\033[31m-------------------------\033[0m" << std::endl;
			std::cout << "\033[31mInvalid format on the line: \033[0m" << "\033[31m" << line_number << "\033[0m" << std::endl;
			std::cout << "\033[31m-------------------------\033[0m" << std::endl;

		}

		if (!inSection) {
			if (line == section_name) {
				inSection = true;
			}
		}
		else {
			if (!line.empty() && line[0] == '[') {
				inSection = false;
			}
			else {
				size_t equalPos = line.find('=');
				if (equalPos != std::string::npos)
				{

					std::string current_var_name = line.substr(0, equalPos);
					std::string current_var_value = line.substr(equalPos + 1, line.size() - 1);
			
					auto it = std::find_if(section_vars.begin(), section_vars.end(),
						[&current_var_name](const std::pair<std::string, std::string>& pair) {
							return pair.first == current_var_name;
						});

					if (it != section_vars.end()) {
						it->second = current_var_value;
					}
					else {
						section_vars.push_back({ current_var_name, current_var_value });
					}
				}
			}
		}
	}

	auto it = std::find_if(section_vars.begin(), section_vars.end(),
		[&var_name](const std::pair<std::string, std::string>& pair) {
			return pair.first == var_name;
		});

	if (it != section_vars.end()) {
		return  it->second;
	}
	else {
		std::cout << "Key is not found. Other vars in section: " << std::endl;
		for (const auto& pair : section_vars)
		{
			std::cout << "|   " << pair.first << "   |" << std::endl;
		}
		return "";
	}
};

// Print function
void ini_parser::print_file() {
	std::string line;
	while (std::getline(m_file, line)) {
		std::cout << line << std::endl;
	}
}

// Destructor
ini_parser::~ini_parser() {
	if (m_file.is_open()) m_file.close();
}

