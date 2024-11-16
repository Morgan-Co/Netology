#include "ini_parser.h"

ini_parser::ini_parser(std::string file_name) {
	std::ifstream file(file_name);
	if (!file.is_open())
		throw std::runtime_error("Cannot open file: " + file_name);
	m_file = std::move(file);
	file.close();
};

void ini_parser::get_variable_name(std::string& line) {
	size_t equalPos = line.find('=');
	if (equalPos == std::string::npos) return;
	line = line.substr(0, equalPos);
}

void ini_parser::remove_comments(std::string& line) {
	char commentChar = ';';
	size_t commentCharPos = line.find(commentChar);
	if (commentCharPos != std::string::npos) {
		line = line.substr(0, commentCharPos);
	}
}

void ini_parser::trim_spaces(std::string& line) {
	size_t start = line.find_first_not_of(' ');
	size_t end = line.find_last_not_of(' ');
	if (start == std::string::npos) return;
	//if (line.empty() && line.find_first_not_of(" \t") == std::string::npos) {
	//	line = "";
	//	return;
	//}
	line = line.substr(start, end - start + 1);
	line = std::regex_replace(line, std::regex(R"(\s*=\s*)"), "=");

	//size_t equalPos = line.find('=');
	//if (equalPos != std::string::npos) {
	//	size_t valueStart = line.find_first_not_of(' ', equalPos + 1);
	//	size_t valueEnd = 
	//}
}

std::string ini_parser::generate_line(const std::string& line) {
	std::string generated_line = line;
	//Delete comments ------------------------------------------
	char commentChar = ';';
	size_t commentCharPos = line.find(commentChar);
	if (commentCharPos != std::string::npos) {
		generated_line = line.substr(0, commentCharPos);
	}

	//Trim spaces ----------------------------------------------
	generated_line.erase(std::remove(generated_line.begin(), generated_line.end(), ' '), generated_line.end());
	return generated_line;
}


std::string ini_parser::get_value(std::string input_data) {
	std::string section_name, var_name;

	size_t dot_position = input_data.find(".");

	if (dot_position != std::string::npos)
	{
		section_name = "[" + input_data.substr(0, dot_position) + "]";
		var_name = input_data.substr(dot_position + 1, input_data.size() - 1) + "=";
	}
	std::cout << "Section: " << section_name << std::endl;
	std::cout << "Var Name: " << var_name << std::endl;




	std::string line;
	bool inSection = false;
	std::string finish_value;
	while (std::getline(m_file, line)) {
		//generate_line(line);
		remove_comments(line);
		trim_spaces(line);
		//std::string generated_line = generate_line(line);
		//std::cout << "|" << line << std::endl;
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
				if (line.find(var_name) != std::string::npos) {
					finish_value = line.substr(line.find('=') + 1, line.size() - 1);
					//std::cout << "Finish value: " << finish_value << std::endl;
					trim_spaces(finish_value);
				}
			}
		}
	}
	return finish_value;
	//return "";
};

void ini_parser::print_file() {
	std::string line;
	while (std::getline(m_file, line)) {
		std::cout << line << std::endl;
	}
}

ini_parser::~ini_parser() {
	if (m_file.is_open()) m_file.close();
}

